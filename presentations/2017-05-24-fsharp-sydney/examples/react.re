module Page = {
  include ReactRe.Component;
  type props = {message: string};
  let name = "Page";
  let handleClick _ _ => { Js.log "clicked!"; };
  let render {props, handler} => {
    let message = ReactRe.stringToElement props.message;
    <div onClick=(handler handleClick)> message </div>;
  }
};
include ReactRe.CreateComponent Page;
let createElement ::message => wrapProps {message: message};
