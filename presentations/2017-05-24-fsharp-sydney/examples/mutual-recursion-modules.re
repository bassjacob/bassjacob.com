module rec Foo: {type t = int; let bar: Bar.t;} = {
  type t = int;
  let bar = "3";
}
and Bar: {type t = string; let foo: Foo.t;} = {
  type t = string;
  let foo = 3;
};
