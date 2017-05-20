open Cell;

module Index = {
  let handlePages path => {
    let file = Js.String.replace "/" "" path |> (fun x => x ^ ".md");

    Fs.readdirP "./pages"
      |> P.bind (fun pages => {
        if (Js.Array.includes file pages) {
          Fs.readFileP {j|./pages/$(file)|j} "utf-8";
        } else {
          Js.Promise.reject (Not_found);
        }
      })
      |> P.fmap (fun (page: string): PageLayout.page => {
        let matterData = Matter.parse page;
        let content = matterData##content;
        let data = Js.Json.decodeObject matterData##data;

        let title = Option.bind (fun obj => Js.Dict.get obj "title") data
          |> Option.bind (fun str => Js.Json.decodeString str)
          |> Option.fromOption "";

        {
          content: Marked.render content,
          title: title
        };
      });
  };

  let render data => {
    PageLayout.render data
      |> (fun content => DefaultLayout.makeLocals content::content ())
      |> (fun content => DefaultLayout.render content ());
  };

  let controller req res next => {
    handlePages (Express.Request.path req)
      |> P.fmap render
      |> P.fmap (Server.send res)
      |> Helpers.promiseControllerErrorHandler next;
  };
};
