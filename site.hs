--------------------------------------------------------------------------------
{-# LANGUAGE OverloadedStrings #-}
import           Data.Monoid            (mappend,(<>),mconcat)
import           Hakyll
import           Control.Monad          (forM,forM_,mzero)
import           Data.Maybe             (fromMaybe)
import           Control.Applicative   (empty)
import           Data.List              (sortBy,isInfixOf,isSuffixOf)
import           Data.Ord               (comparing)
import           System.Locale          (defaultTimeLocale)
import           System.FilePath.Posix  (takeBaseName,takeDirectory,(</>),splitFileName)
import           Text.Pandoc.Options
import           Data.Aeson
import           Control.Arrow
import qualified Data.ByteString.Lazy  as BS

--------------------------------------------------------------------------------
getTalks :: IO [Talk]
getTalks = do
  talks <- BS.readFile "talks.json"
  case eitherDecode talks of
      Left  err -> error err
      Right val -> return val

main :: IO ()
main = do
  t <- getTalks
  hakyll $ do
    match "images/*" $ do
        route   idRoute
        compile copyFileCompiler

    match "css/*" $ do
        route   idRoute
        compile compressCssCompiler

    match "posts/*" $ do
        route cleanRoute
        compile $ pandocCompiler
            >>= loadAndApplyTemplate "templates/post.html"    dateCtx
            >>= loadAndApplyTemplate "templates/default.html" dateCtx
            >>= relativizeUrls
            >>= cleanIndexUrls

    match "drafts/*" $ do
        route cleanRoute
        compile $ pandocCompiler
            >>= loadAndApplyTemplate "templates/post.html"    dateCtx
            >>= loadAndApplyTemplate "templates/default.html" dateCtx
            >>= relativizeUrls
            >>= cleanIndexUrls

    match "assets/**/*" $ do
        route   idRoute
        compile copyFileCompiler

    match "images/*" $ do
        route   idRoute
        compile copyFileCompiler

    match "pages/*" $ do
      route cleanRouteWithoutDir
      compile $ pandocCompiler
        >>= loadAndApplyTemplate "templates/default.html" defaultContext
        >>= relativizeUrls
        >>= cleanIndexUrls

    create ["talks.html"] $ do
      route cleanRoute
      compile $ do
            makeItem ""
              >>= loadAndApplyTemplate "templates/talks.html" ( talksCtx t )
              >>= loadAndApplyTemplate "templates/default.html" ( talksCtx t )
              >>= relativizeUrls
              >>= cleanIndexUrls

    create ["posts.html"] $ do
        route cleanRoute
        compile $ do
            posts <- recentFirst =<< loadAll "posts/*"
            let archiveCtx = listField "posts" dateCtx (return posts) `mappend`
                             constField "title" "Archives"            `mappend`
                             defaultContext

            makeItem ""
                >>= loadAndApplyTemplate "templates/posts.html" archiveCtx
                >>= loadAndApplyTemplate "templates/default.html" archiveCtx
                >>= relativizeUrls
                >>= cleanIndexUrls

    match "index.html" $ do
        route idRoute
        compile $ do
            posts <- fmap (take 5) (recentFirst =<< loadAll "posts/*")

            let indexCtx = mconcat [ listField "posts" dateCtx (return posts)
                                   , talkCtx $ head t
                                   , constField "title" "Home"
                                   ]

            getResourceBody
                >>= applyAsTemplate indexCtx
                >>= loadAndApplyTemplate "templates/default.html" indexCtx
                >>= relativizeUrls
                >>= cleanIndexUrls

    match "templates/*" $ compile templateBodyCompiler
    match "templates/partials/*" $ compile templateBodyCompiler

--------------------------------------------------------------------------------
dateCtx :: Context String
dateCtx =
    dateField "date" "%B %e, %Y" `mappend`
    defaultContext

cleanRoute :: Routes
cleanRoute = customRoute createIndexRoute
  where createIndexRoute ident = takeDirectory p </>
          takeBaseName p </> "index.html"
            where p = toFilePath ident

cleanRouteWithoutDir :: Routes
cleanRouteWithoutDir = customRoute createIndexRoute
  where
    createIndexRoute ident = takeBaseName p </> "index.html"
                            where p = toFilePath ident

cleanIndexUrls :: Item String -> Compiler (Item String)
cleanIndexUrls = return . fmap (withUrls cleanIndex)

cleanIndex :: String -> String
cleanIndex url
    | idx `isSuffixOf` url = take (length url - length idx) url
    | otherwise            = url
  where idx = "index.html"

talkCtx :: Talk -> Context String
talkCtx talk = mconcat
    [ (constField "talkTitle" . title) talk
    , (constField "talkLocation" . location) talk
    , (constField "talkDate" . date) talk
    , field "talkSlides" (\_ -> maybe empty return (slides talk))
    , field "talkVideo" (\_ -> maybe empty return (video talk))
    , field "talkImage" (\_ -> maybe empty return (image talk))
    , defaultContext
    ]

talksCtx :: [Talk] -> Context String
talksCtx talks =
  listField "talks"
    (mconcat
      [ field "title" (return . title . itemBody)
      , field "location" (return . location . itemBody)
      , field "date" (return . date . itemBody)
      , field "slides" (maybe empty return . slides . itemBody)
      , field "video" (maybe empty return . video . itemBody)
      , field "image" (maybe empty return . image . itemBody)
      ]
    )
    (sequence . map makeItem $ talks) `mappend` defaultContext

--------------------------------------------------------------------------------

data Talk = Talk
  { title :: String
  , location :: String
  , date :: String
  , slides :: Maybe String
  , video :: Maybe String
  , image :: Maybe String
  } deriving (Show)

instance FromJSON Talk where
  parseJSON (Object o) = Talk
    <$> o .: "title"
    <*> o .: "location"
    <*> o .: "date"
    <*> o .:? "slides"
    <*> o .:? "video"
    <*> o .:? "image"
