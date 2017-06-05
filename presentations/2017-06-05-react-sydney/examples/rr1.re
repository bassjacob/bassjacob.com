module Component = {
  include ReactRe.Component;
  type props = unit;
  let name = "Hello World!";
  let render _ => {
    <div>(ReactRe.stringToElement "Hello World!")</div>
  };
};

include ReactRe.CreateComponent Component;

let createElement = wrapProps ();

