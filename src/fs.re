external readFile : string => string => ((Js_null_undefined.t exn => string => 'a) [@bs.uncurry]) => 'a = "" [@@bs.module "fs"];
external readdir : string => (Js_null_undefined.t exn => array string => 'a) [@bs.uncurry] => 'a = "readdir" [@@bs.module "fs"];

let readdirP = P.promisify1 readdir;
let readFileP = P.promisify2 readFile;
