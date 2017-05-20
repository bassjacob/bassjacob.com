module Index = {
  let mapPages _ => {
    Fs.readdirP "./pages"
      |> P.fmap (fun pages => {
        Array.map (fun (page: string): SitemapLayout.url => {
          {
            location: "https://bassjacob.com/" ^ (Js.String.replace ".md" "" page),
            changeFreq: "Weekly",
            priority: "1.0"
          };
        }) pages;
      });
  };

  let mapPosts _ => {
    let postsMap: SitemapLayout.url = {
      location: "https://bassjacob.com/posts/",
      changeFreq: "Weekly",
      priority: "0.7"
    };

    Fs.readdirP "./posts"
      |> P.fmap (fun posts => {
        Array.map (fun (post: string): SitemapLayout.url => {
          {
            location: "https://bassjacob.com/posts/" ^ (Js.String.replace ".md" "" post),
            changeFreq: "Monthly",
            priority: "1.0"
          };
        }) posts;
      })
      |> P.fmap (fun posts => Array.append posts [|postsMap|]);
  };

  let render urls => {
    Array.fold_right (fun b a => Array.append b a) urls [||]
      |> SitemapLayout.render;
  };

  let controller req res next => {
    let _ = Server.set res "Content-Type" "text/xml";

    Js.Promise.all [|(mapPages ()), (mapPosts ())|]
      |> P.fmap render
      |> P.fmap (Server.send res);
  };
};
