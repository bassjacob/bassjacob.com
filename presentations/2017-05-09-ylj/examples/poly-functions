let const : 'a => 'b => 'a = fun x y => x;

let wrong_const : 'a => 'b => 'a = fun x y => y; /* compiles */

let locallyAbstractConst (type a b) (x: a) (_: b) => x;

let forallConst: 'a 'b .'a => 'b => 'a = fun x _ => x;
