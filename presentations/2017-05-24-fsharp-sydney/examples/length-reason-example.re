let rec sum xs =>
  switch xs {
  | [] => 0
  | [x, ...xs] => x + sum xs
  };
