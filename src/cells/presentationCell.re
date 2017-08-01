module Index = {
  let render matterData => {
    let data = Js.Json.decodeObject matterData##data;

    let title = Option.bind (fun obj => Js.Dict.get obj "title") data
      |> Option.bind (fun str => Js.Json.decodeString str)
      |> Option.fromOption "";

    let subtitle = Option.bind (fun obj => Js.Dict.get obj "subtitle") data
      |> Option.bind (fun str => Js.Json.decodeString str)
      |> Option.fromOption "";

    PresentationLayout.render {
      title: title,
      subtitle: subtitle,
      content: matterData##content,
    };
  };

  let controller req res next => {
    Express.Request.path req
      |> Js.String.replace "/" ""
      |> (fun x => "./" ^ x ^ "presentation.html")
      |> (fun file => Fs.readFileP file "utf-8")
      |> P.fmap Matter.parse
      |> P.fmap render
      |> P.fmap (Server.send res)
      |> Cell.Helpers.promiseControllerErrorHandler next;
  };
};
