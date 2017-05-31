open Express;

let app = express ();

App.get app path::"/" @@ Middleware.from (fun _ res _ => {
  Response.sendString res "hello world";
});

App.listen app port::3000;
