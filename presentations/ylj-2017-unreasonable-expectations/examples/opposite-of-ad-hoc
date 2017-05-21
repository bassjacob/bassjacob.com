module Demo(F: Functor.Functor) => {
  let eg1 x => F.fmap (fun a => a + 1) x;
  let eg2 f x => F.fmap f x;
};

module ListDemo = Demo(List);
module OptionDemo = Demo(Option);
