type term = int; /* simple type alias */

type term = int | bool; /* syntax error */

type term = Int int | Bool bool; /* using an ADT to express a polymorphic type */

/* type error! int and bool can't both be returned! */
let eval: type a. term a => a = fun t
  switch (t) {
  | Int x => x
  | Bool b => b
  };
