let style = ReactDOMRe.Style.make
  display::"flex"
  width::"50px"
  height::"50px"
  background::"gray"
  ();

module Component = {
  /* as above */
  let render _ => {
    <div style=style> </div>
  };
};

