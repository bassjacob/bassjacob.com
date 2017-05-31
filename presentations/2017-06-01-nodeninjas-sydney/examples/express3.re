let extractAppMethod method =>
  switch method {
  | GET => App.get
  | POST => App.post
  };

let applyRoute server route =>
  switch route {
  | ErrorRoute handler =>
      App.use server handler
  | Route (method, path, handler) =>
      (extractMethod method) server ::path handler
  | Use handler =>
      App.use server handler
  };

