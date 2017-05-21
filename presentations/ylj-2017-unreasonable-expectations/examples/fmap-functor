module Functor = {
  module type S = {
    type t 'a;
    let fmap: ('a => 'b) => t 'a => t 'b;
  };

  module type Functor = {
    include S;
    let (<$>): ('a => 'b) => t 'a => t 'b;
  };

  module Make (S: S) :(Functor with type t 'a = S.t 'a) => {
    include S;
    let (<$>) = S.fmap;
  };
};
