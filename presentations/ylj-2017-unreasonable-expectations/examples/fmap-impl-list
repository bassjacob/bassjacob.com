module List = {
  include List;
  include Functor.Make {
    type t 'a = list 'a;
    let fmap f list =>
      fold_right
        (fun a b => [f a, ...b])
        list
        [];
  };
};

List.((fun a => a + 1) <$> [1, 2, 3, 4]);
