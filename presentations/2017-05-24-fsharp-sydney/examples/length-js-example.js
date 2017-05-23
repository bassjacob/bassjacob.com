let sum = function (xs) {
  if (length(xs) === 0) {
    return 0;
  }

  return xs[0] + sum(xs.slice(1));
}
