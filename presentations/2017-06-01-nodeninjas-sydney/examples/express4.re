let routes = [
  (GET, "/", (fun req res next => Response.sendString res "hello world")),
  Use (ErrorCell.Index.controller Not_found),
  ErrorRoute (ErrorCell.Index.controller)
];

let app = express ();
List.iter (applyRoute app) routes;
App.listen app port::3000;
