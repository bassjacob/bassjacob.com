type letters = A | B | C | D;

let takesLetters (letter: letters): string => {
  switch letter {
  | A => "a"
  | B => "b"
  | C => "c"
  | _ => "d"
  };
};

Js.log @@ takesLetters A; /* logs "a" */
Js.log @@ takesLetters E; /* will not compile */
