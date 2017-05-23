module List = {
  type t 'a = Null | Cons ('a) (t 'a);
  let rec length list => switch list {
  | Null => 0
  | Cons _ rest => 1 + length rest
  };
};

let intList = List.Cons 1 (List.Cons 2 (List.Cons 3 List.Null));

let intList' = List.(1 (Cons 2 (Cons 3 Null)));

let intList'' = {
  open List;
  1 (Cons 2 (Cons 3 Null)));
};
