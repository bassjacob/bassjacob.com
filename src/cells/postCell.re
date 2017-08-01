open Cell;

module Index = {
  open P.Helpers;

  let extractPostData postFile : option PostsLayout.post => {
    let matterData = Matter.read @@ postFile;

    let data = Js.Json.decodeObject matterData##data;

    let content = Js.String.substrAtMost from::0 length::200 matterData##content
      |> (fun x => x ^ "...")
      |> Marked.render;
		let summary = Option.bind (fun obj => Js.Dict.get obj "summary") data
      |> Option.bind (fun str => Js.Json.decodeString str)
      |> Option.fromOption content;
		let isDraft = Option.bind (fun obj => Js.Dict.get obj "draft") data
			|> Option.bind (fun bool => Js.Json.decodeBoolean bool)
			|> Option.fmap Js.to_bool
			|> Option.fromOption false;
    let title = Option.bind (fun obj => Js.Dict.get obj "title") data
      |> Option.bind (fun str => Js.Json.decodeString str)
      |> Option.fromOption "N/A";
    let date = Option.bind (fun obj => Js.Dict.get obj "date") data
      |> Option.bind (fun str => Js.Json.decodeString str)
      |> Option.fromOption "";
    let url = postFile
			|> Js_string.replaceByRe (Js_re.fromString "./posts/") ""
			|> Js_string.replaceByRe (Js_re.fromString "./presentations/") ""
			|> Js_string.replaceByRe (Js_re.fromString "/presentation.html") ""
			|> Js_string.replaceByRe (Js_re.fromString ".md") "";

		isDraft ? None : Some { content: summary, date, title, url };
  };

  let gatherPostData dir => Fs.readdirP dir
		|<> Array.map (fun v => dir ^ v)
    |<> Array.map extractPostData
		|<> (fun x => Array.fold_right (fun a b => switch (a) { | None => b | Some v => [v, ...b] }) x []);

	let gatherPresentationData dir => Fs.readdirP dir
		|<> Array.map (fun v => dir ^ v ^ "/presentation.html")
		|<> Array.map extractPostData
		|<> (fun x => Array.fold_right (fun a b => switch (a) { | None => b | Some v => [v, ...b] }) x []);

  let controller _ res next => {
		Js.Promise.all2 (gatherPostData "./posts/", gatherPresentationData "./presentations/")
    	|<> (fun (a1, a2) => List.append a1 a2)
			|<> List.sort compare
			|<> Array.of_list
			|<> (fun posts => PostsLayout.render { posts: posts })
			|<> (fun content => DefaultLayout.makeLocals content::content ())
			|<> (fun content => DefaultLayout.render content ())
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

        Js.Re.test postFile (Js.Re.fromString "\.html$")
          ?  { content: content, title: title, date: date }
          :  { content: Marked.render content, title: title, date: date };
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

		let post = {j|./posts/$(id).md|j};
		let presentation = {j|./presentations/$(id)/presentation.html|j};

    extractPostData post
			|> Js.Promise.catch (fun _ => extractPostData presentation)
      |<> render
      |<> Server.send res
      |> Helpers.promiseControllerErrorHandler next;
  };
};
