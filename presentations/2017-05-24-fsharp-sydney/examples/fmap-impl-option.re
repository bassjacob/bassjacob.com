module Option = {
  include
    Functor.Make {
      type t 'a = option 'a;
      let fmap f opt =>
        switch opt {
        | None => None
        | Some x => Some (f x)
        };
    };
};

Option.((fun a => a + 1) <$> Some 1);
