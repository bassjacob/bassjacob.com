open Cell;

module Index = {
  open P.Helpers;

  let extractPostData postFile : PostsLayout.post => {
    let matterData = Matter.read @@ "./posts/" ^ postFile;

    let data = Js.Json.decodeObject matterData##data;

    let content = Js.String.substrAtMost from::0 length::200 matterData##content
      |> (fun x => x ^ "...")
      |> Marked.render;
    let title = Option.bind (fun obj => Js.Dict.get obj "title") data
      |> Option.bind (fun str => Js.Json.decodeString str)
      |> Option.fromOption "N/A";
    let date = Option.bind (fun obj => Js.Dict.get obj "date") data
      |> Option.bind (fun str => Js.Json.decodeString str)
      |> Option.fromOption "";
    let url = Js_string.replaceByRe (Js_re.fromString ".md") "" postFile;

    { content, date, title, url };
  };

  let render posts => {
    PostsLayout.render { posts: Array.map extractPostData posts }
      |> (fun content => DefaultLayout.makeLocals content::content ())
      |> (fun content => DefaultLayout.render content ());
  };

  let controller _ res next => {
    Fs.readdirP "./posts"
      |<> render
      |<> Server.send res
      |> Helpers.promiseControllerErrorHandler next;
  };
};

module Show = {
  open P.Helpers;

  let extractPostData postFile => {
    Fs.readFileP postFile "utf-8"
      |<> (fun (file: string): PostLayout.post => {
        let matterData = Matter.parse file;
        let content = matterData##content;
        let data = Js.Json.decodeObject matterData##data;

        let title = Option.bind (fun obj => Js.Dict.get obj "title") data
          |> Option.bind (fun str => Js.Json.decodeString str)
          |> Option.fromOption "N/A";
        let date = Option.bind (fun obj => Js.Dict.get obj "date") data
          |> Option.bind (fun str => Js.Json.decodeString str)
          |> Option.fromOption "";

        {
          content: Marked.render content,
          title: title,
          date: date,
        };
      });
  };

  let render post => {
    PostLayout.render post
      |> (fun content => DefaultLayout.makeLocals content::content ())
      |> (fun content => DefaultLayout.render content ());
  };

  let controller req res next => {
    let params = Express.Request.params req;
    let id = Js.Dict.get params "id"
      |> Option.bind Js.Json.decodeString
      |> Option.fromOption "";

    extractPostData {j|./posts/$(id).md|j}
      |<> render
      |<> Server.send res
      |> Helpers.promiseControllerErrorHandler next;
  };
};
