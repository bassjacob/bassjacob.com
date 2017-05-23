let css display::(display: string)="block" width::(width: string) =>
  "{\n" ^ "display: " ^ display ^ ";\n" ^ "width: " ^ width ^ ";\n" ^ "}";

/* { display: flex; width: 50px; } */
css display::"flex" width::"50px";

/* { display: block; width: 50px; } */
css width::"50px";
