---
title: reacting reasonably
---
<section>
  <section>
    <h1>in the beginning...</h1>
    <pre class="language-javascript">
      <code>
$('.app').html('hello world!');
      </code>
    </pre>
  </section>
  <section>
    <h1>generations later...</h1>
    <pre class="language-javascript">
      <code>
document.querySelector('.app').innerHTML = 'hello world!';
      </code>
    </pre>
  </section>
  <section>
    <h1>but these days...</h1>
    <pre>
      <code>
$ cat webpack.config.js | wc -l # number of lines in my webpack config
      206

$ cat package.json | wc -l # number of lines in my package.json
      205

$ tree -d | grep babel | wc -l # number of folders that match "babel"
      424

$ du -chd1 # size on disk of all of my dependencies
      1.7G total
      </code>
    </pre>
  </section>
  <section><img src="assets/projectlogos.png" alt=""></section>
  <section>
    <h1>the year<i style="opacity: 0;">s</i> of javascript <i>fatigue</i></h1>
  </section>
  <section>
    <h1>the year<i style="color: #cbaabc;">s</i> of javascript <i>fatigue</i></h1>
  </section>
  <section>
    <img src="assets/metalang.png" alt="">
  </section>
</section>

<section>
  <section>
    <img src="assets/reasonml.png" alt="">
  </section>
  <section>
    <h1>so what's the <i style="color: #cbaabc;">reason</i> for all of this, anyway?</h1>
  </section>
  <section>
    <h1>who here has dealt with a runtime error?</h1>
  </section>
  <section>
    <h1>null</h1>
    <h2>hoare's billion dollar mistake</h2>
  </section>
  <section>
    <h1>unit tests can only tell you when something is broken</h1>
    <h2>they can't tell you that something is ok</h2>
  </section>
  <section>
    <h1>make illegal states unrepresentable</h1>
  </section>
  <section>
    <pre class="language-javascript" data-src="examples/brokencontroller.js"></pre>
  </section>
</section>

<section>
  <section>
    <h1>but jacob <small><i>I hear you say</i></small></h1>
    <h2>there are <i>already</i> type systems for javascript</h2>
  </section>
</section>

<section>
  <section>
    <h1>flow</h1>
  </section>
  <section>
    <pre class="language-javascript" data-src="examples/flow1.js"></pre>
  </section>
  <section>
    <pre class="language-reason" data-src="examples/flow1.re"></pre>
  </section>
  <section style="flex-direction: row">
    <div>
      <img src="assets/wizard2.png">
    </div>
    <div>
      <h3>merlin says</h3>
      <p>this pattern-matching is not exhaustive.</p>
      <p>Here is an example of a value that is not matched: C</p>
    </div>
  </section>
</section>

<section>
  <section>
    <h1>typescript</h1>
  </section>
  <section>
    <pre class="language-javascript" data-src="examples/typescript1.js"></pre>
  </section>
  <section>
    <pre class="language-reason" data-src="examples/typescript1.re"></pre>
  </section>
  <section style="flex-direction: row">
    <div>
      <img src="assets/wizard2.png">
    </div>
    <div>
      <h3>merlin says</h3>
      <p>This expression has type Js.t { baz : 'a }</p>
      <p>but an expression was expected of type Js.t { bar : Js.fn [ `Arity_0 ] 'b, .. }</p>
      <p>The first object type has no method bar</p>
    </div>
  </section>
</section>

<section>
  <section>
    <h1>hello world!</h1>
  </section>
  <section>
    <pre class="language-reason" data-src="examples/rr1.re"></pre>
  </section>
  <section>
    <pre class="language-reason" data-src="examples/rr2.re"></pre>
  </section>
  <section>
    <pre class="language-reason" data-src="examples/rr3.re"></pre>
  </section>
  <section>
    <pre class="language-reason" data-src="examples/rr4.re"></pre>
  </section>
  <section>
    <pre class="language-reason" data-src="examples/rr5.re"></pre>
  </section>
  <section>
    <pre class="language-reason" data-src="examples/rr6.re"></pre>
  </section>
</section>

<section>
  <section>
    <pre class="language-javascript" data-src="examples/spaghetti"></pre>
  </section>
  <section>
    <pre class="language-jsx" data-src="examples/react"></pre>
  </section>
  <section>
    <pre class="language-javascript" data-src="examples/flow"></pre>
  </section>
  <section>
    <pre class="language-haskell" data-src="examples/haskell"></pre>
  </section>
  <section>
    <img src="assets/reasonml.png" />
  </section>
</section>

<section>
  <section>
    <h1>reason sydney meetup: 14th June</h1>
    <h2><a href="https://www.meetup.com/reason-sydney/">meetup.com/reason-sydney</a></h2>
  </section>
  <section>
    <h1>follow us</h1>
    <h1>@reasonsydney</h1>
  </section>
</section>
