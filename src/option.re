let fromOption default optional => {
  switch optional {
  | None => default
  | Some v => v
  };
};

let fmap f optional => {
  switch optional {
  | None => None
  | Some v => Some (f v)
  };
};

let return (type a) (x: a): (option a) => Some x;

let bind (type a) (type b) (f: a => option b) (x: option a): (option b) => {
  switch x {
  | Some y => f y
  | None => None
  };
};
