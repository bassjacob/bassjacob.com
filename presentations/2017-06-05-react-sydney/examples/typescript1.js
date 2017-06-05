function foo (hasMethodBar) {
  return hasMethodBar.bar();
}

foo({ baz: () => "should fail to compile, but doesn't" });

foo({ bar: () => "compiles" });
