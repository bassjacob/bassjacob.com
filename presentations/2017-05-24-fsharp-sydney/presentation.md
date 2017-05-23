---
title: an introduction to reason
---

<section>
  <section>
    <img src="assets/reasonml.png" />
  </section>
  <section>
    <h1>the <i>reason</i> for reason?</h1>
  </section>
  <section>
    <h2>can programming be liberated</h2>
    <h2>from</h2>
    <h2>the von neumann <small>(imperative)</small> style?</h2>
  </section>
  <section>
    <img src="assets/metalang.png" />
  </section>
  <section>
    <h2>JavaScript</h2>
    <pre class="language-javascript" data-src="examples/length-js-example.js"></pre>
  </section>
  <section>
    <h2>Reason</h2>
    <pre class="language-reason" data-src="examples/length-reason-example.re"></pre>
  </section>
</section>
<section>
  <section>
    <h1>A Sprinting Tour of the Syntax</h1>
  </section>
  <section>
    <h2>functions</h2>
    <pre class="language-reason" data-src="examples/functions.re"></pre>
  </section>
  <section>
    <h2>parametric polymorphism</h2>
    <pre class="language-reason" data-src="examples/poly-functions.re"></pre>
  </section>
  <section>
    <h2>simple types</h2>
    <pre class="language-reason" data-src="examples/types.re"></pre>
  </section>
  <section>
    <h2>mutually recursive types</h2>
    <pre class="language-reason" data-src="examples/poly-types.re"></pre>
  </section>
</section>
<section>
  <section>
    <h2>same same</h2>
    <h1>but different?</h1>
  </section>
  <section>
    <h1>labeled arguments to functions</h1>
  </section>
  <section>
    <pre class="language-reason" data-src="examples/labeled-args-1.re"></pre>
  </section>
  <section>
    <pre class="language-reason" data-src="examples/labeled-args-2.re"></pre>
  </section>
  <section>
    <pre class="language-reason" data-src="examples/labeled-args-3.re"></pre>
  </section>
</section>
<section>
  <section>
    <h1>first class modules</h1>
  </section>
  <section>
    <h2>types (signatures)</h2>
    <pre class="language-reason" data-src="examples/modules-types.re"></pre>
  </section>
  <section style="flex-direction: column">
    <h2>structures</h2>
    <pre class="language-reason" data-src="examples/modules.re"></pre>
  </section>
  <section>
    <pre class="language-reason" data-src="examples/module-usage.re"></pre>
  </section>
  <section>
    <h2>mutually recursive modules</h1>
    <pre class="language-reason" data-src="examples/mutual-recursion-modules.re"></pre>
    <pre class="language-reason" data-src="examples/mutual-recursion-modules-2.re"></pre>
  </section>
  <section>
    <pre class="language-reason" data-src="examples/first-class-modules.re"></pre>
  </section>
  <section style="flex-direction: row">
    <div style="width: 100%">
      <h2>List.rei</h2>
      <pre class="language-reason" data-src="examples/first-class-files-types.re"></pre>
    </div>
    <div style="width: 100%">
      <h2>List.re</h2>
      <pre class="language-reason" data-src="examples/first-class-files.re"></pre>
    </div>
  </section>
</section>
<section>
  <section>
    <h1>functors</h1>
  </section>
  <section style="flex-direction: column">
    <h1>Not this kind.</h1>
    <h2>fmap :: Functor f => (a -> b) -> f a -> f b</h2>
  </section>
  <section>
    <pre class="language-reason" data-src="examples/functors.re"></pre>
  </section>
  <section>
    <h1>we could make fmap functors this way!</h1>
  </section>
  <section>
    <pre class="language-reason" data-src="examples/fmap-functor.re"></pre>
  </section>
  <section style="flex-direction: row">
    <div style="width: 100%">
      <h2>option functor</h2>
      <pre class="language-reason" data-src="examples/fmap-impl-option.re"></pre>
    </div>
    <div style="width: 100%">
      <h2>list functor</h2>
      <pre class="language-reason" data-src="examples/fmap-impl-list.re"></pre>
    </div>
  </section>
  <section>
    <h2>what's the opposite of ad-hoc?</h2>
    <pre class="language-reason" data-src="examples/opposite-of-ad-hoc.re"></pre>
  </section>
</section>

<section>
  <section>
    <h1>gadt's</h1>
  </section>

  <section>
    <pre class="language-reason" data-src="examples/gadt-1.re"></pre>
  </section>

  <section>
    <pre class="language-reason" data-src="examples/gadt-2.re"></pre>
  </section>

  <section>
    <pre class="language-reason" data-src="examples/gadt-3.re"></pre>
  </section>
</section>

<section>
  <section>
    <h1>ppx</h1>
  </section>
</section>

<section>
  <section>
    <h1>FFI and Interop</h1>
  </section>

  <section>
    <h1>native</h1>
  </section>

  <section>
    <h1>bucklescript</h1>
  </section>

  <section>
    <h1>reactjs</h1>
  </section>
</section>
