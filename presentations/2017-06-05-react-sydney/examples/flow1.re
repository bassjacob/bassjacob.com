type a = A | B | C;

let foo (a:a): string => {
  switch (a) {
  | A => "A"
  | B => "B"
  };
};
