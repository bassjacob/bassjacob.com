module Component = {
  /* same setup */

  let render {state, updater} => {
    let activeStyle = switchStyle state;
    <div
      onMouseEnter=(updater handleHover)
      onMouseLeave=(updater handleHover)
      style=(ReactDOMRe.Style.combine boxStyle activeStyle)
    />
  };
};
