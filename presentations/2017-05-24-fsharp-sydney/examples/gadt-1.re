type term 'a =
  | Zero :term int
  | Succ (term int) :term int
  | Bool bool: term bool
  | IsZero (term int): term bool
  | If (term bool) (term 'a) (term 'a): term 'a;
