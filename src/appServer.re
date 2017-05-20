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
];

makeServer routes (int_of_string port) (onListen port);
