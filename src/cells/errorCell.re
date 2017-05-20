module Index = {
  let render _ => {
    NotFoundLayout.render ()
      |> (fun content => DefaultLayout.makeLocals content::content ())
      |> (fun content => DefaultLayout.render content ());
  };

  let controller err _ res _ => {
    render ()
      |> Server.send res;
  };
};
