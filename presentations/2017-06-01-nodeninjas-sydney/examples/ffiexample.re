module Fs = {
  external readFile :
    string
    => string
    => ((Js_null_undefined.t exn => string => 'a) [@bs.uncurry])
    => 'a
    = "" [@@bs.module "fs"];
};

Fs.readFile "/path/to/file" "utf-8" (fun _ data => Js.log data);
