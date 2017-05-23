let css display::(display: string)="block" width::(width: string)="50px" () =>
  "{\n" ^ "display: " ^ display ^ ";\n" ^ "width: " ^ width ^ ";\n" ^ "}";

/* { display: flex; width: 75px; } */
css display::"flex" width::"75px" ();

/* { display: block; width: 75px; } */
css width::"75px" ();

/* { display: block; width: 50px; } */
css ();
