module Component = {
  include ReactRe.Component.Stateful;
  type props = unit;
  let name = "Hello World!";
  type state = {hovered: bool};
  let getInitialState (_: props) => {hovered: false};

  /* ... */

  let render {state, updater} => {
    /* ... */
  };
};

