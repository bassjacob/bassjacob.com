module rec Foo: {type t = int; let bar: Bar.t;} = Foo
and Bar: {type t = string; let foo: Foo.t;} = Bar;
