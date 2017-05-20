open Express;

external dirname : string = "__dirname" [@@bs.val];

external send : Express.Response.t => 'a => Express.done_ = "" [@@bs.send];

external set : Express.Response.t => string => string => unit = "" [@@bs.send];

external listen : App.t => int => (Js.Null_undefined.t Js.Exn.t => unit) [@bs.uncurry] => unit =
  "" [@@bs.send];

type errorMiddlewareFn = Middleware.errorF;

type middlewareFn = Middleware.f;

type asyncMiddlewareFn = Request.t => Response.t => Next.t => Js_promise.t done_;

external asyncFrom : asyncMiddlewareFn => Middleware.t = "%identity";

type method =
  | HEAD
  | GET
  | POST
  | PUT
  | DELETE;

type route =
  | ErrorRoute (errorMiddlewareFn)
  | AsyncRoute (method, string, asyncMiddlewareFn)
  | Route (method, string, middlewareFn)
  | Use middlewareFn
  | UseWithPath (string, middlewareFn)
  | Static (string, string);

let extractAppMethod method =>
  switch method {
  | GET => App.get
  | POST => App.post
  | PUT => Js_exn.raiseError "not implemented yet"
  | DELETE => Js_exn.raiseError "not implemented yet"
  | HEAD => Js_exn.raiseError "not implemented yet"
  };

let applyRoute server route =>
  switch route {
  | ErrorRoute handler => App.use server (Middleware.fromError handler)
  | AsyncRoute (method, path, handler) =>
    (extractAppMethod method) server ::path (asyncFrom handler)
  | Route (method, path, handler) =>
    (extractAppMethod method) server ::path (Middleware.from handler)
  | Use handler => App.use server (Middleware.from handler)
  | UseWithPath (path, handler) => App.useOnPath server ::path (Middleware.from handler)
  | Static (path, folder) =>
    App.useOnPath
      server
      ::path
      (
        Express.Static.make folder (Express.Static.defaultOptions ()) |> Express.Static.asMiddleware
      )
  };

let makeServer routes port onListen => {
  let app = express ();
  List.iter (applyRoute app) routes;
  listen app port onListen;
};

let safeGetEnv default envvar =>
  switch (Sys.getenv envvar) {
  | x => x
  | exception _ => default
  };
