type A = {| t: 'a' |} | {| t: 'b' |} | {| t: 'c' |};

function foo (a: A) {
  switch (a.t) {
    case 'a': return "A"
    case 'b': return "B"
  };
};

foo ({t: 'c' });
