module Functor = {
  module type Input = { type t; };

  module type Output = { include Input; };

  module Make (Input : Input) : (Output with type t = Input.t) => {
    include Input;
  };
};
