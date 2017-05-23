module type Bumper = {
  type t;
  let bump : t => t;
};

module Int_Bumper = {
  type t = int;
  let bump t => t + 1;
};

let bump_list
  (type a)
  ((module B): (module Bumper with type t = a))
  (l: list a) =>
    List.fold_right (fun a b => [B.bump a, ...b]) l [];

bump_list (module Int_Bumper) [1,2,3,4];
