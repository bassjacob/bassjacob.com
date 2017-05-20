open Server;

let onListen port e =>
  switch e {
  | exception (Js.Exn.Error e) =>
    Js.log e;
    Node.Process.exit 1
  | _ => Js.log @@ "Listening on port " ^ port
  };

let port = safeGetEnv "3000" "SERVER_PORT";

let routes = [
  Static ("/public", Node_path.resolve dirname "../../../public"),
  AsyncRoute (GET, "/", PostCell.Index.controller),
  AsyncRoute (GET, "/about", PageCell.Index.controller),
  AsyncRoute (GET, "/posts", PostCell.Index.controller),
  AsyncRoute (GET, "/posts/:id", PostCell.Show.controller),
  AsyncRoute (GET, "/resume", PageCell.Index.controller),
  AsyncRoute (GET, "/talks", PageCell.Index.controller),
  Use (ErrorCell.Index.controller Not_found),
  ErrorRoute (ErrorCell.Index.controller)
];

makeServer routes (int_of_string port) (onListen port);
