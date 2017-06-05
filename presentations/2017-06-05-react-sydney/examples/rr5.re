module Component = {
  /* same setup */

  let handleHover _ e => {
    switch (ReactEventRe.Mouse._type e) {
    | "mouseenter" => Some {hovered: true}
    | _ => Some {hovered: false}
    };
  };

  let switchStyle state => state.hovered ? hoveredStyle : passiveStyle;

  let render {state, updater} => {
    /* we'll come to this in a minute */
  };
};
