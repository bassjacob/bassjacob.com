let rec eval: type a. term a => a = fun t =>
  switch (t) {
  | Zero => 0
  | Succ x => eval x + 1
  | Bool b => b
  | IsZero x => eval x == 0
  | If p x y => (eval p) ? eval x : eval y
  };
