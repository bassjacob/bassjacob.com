type matterResponse = Js.t {
  .
  orig: string,
  data: Js.Json.t,
  content: string
};

external parse : string => matterResponse = "gray-matter" [@@bs.module];
external read : string => matterResponse = "read" [@@bs.module "gray-matter"];
