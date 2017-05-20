include Js.Promise;

let apply resolve reject err v =>
  switch (Js_null_undefined.to_opt err) {
  | None => resolve v [@bs]
  | Some e => reject e [@bs]
  };

let promisify0 f _ => make (fun ::resolve ::reject => f () (apply resolve reject));

let promisify1 f x => make (fun ::resolve ::reject => f x (apply resolve reject));

let promisify2 f x y => make (fun ::resolve ::reject => f x y (apply resolve reject));

module Helpers = {
  let (|<>) p f => p |> then_ (fun z => resolve @@ f z);
  let (|>>) p f => p |> then_ (fun z => all @@ f z);
  let (|<<) p f => p |> catch (fun z => resolve @@ f z);
};
