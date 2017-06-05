let foo hasMethodBar => {
  hasMethodBar#@bar ();
};

foo {"baz": (fun () => "fails to compile!") [@bs]};

foo {"bar": (fun () => "works") [@bs]};
