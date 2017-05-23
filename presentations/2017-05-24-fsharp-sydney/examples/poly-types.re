/* mutually recursive types */
type tree 'a = | Empty | Node 'a (forest 'a)
and forest 'a = | Nil | Cons (tree 'a) (forest 'a);
