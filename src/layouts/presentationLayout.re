type presentations = {
  title: string,
  subtitle: string,
  content: string
};

let whoamiSlide = {j|<section style="flex-direction: column;">
  <h2>\${whoami:-Jacob Bass}</h2>

  <p>github: bassjacob</p>
  <p>twitter: @bassjacob</p>
  <p>web: www.bassjacob.com</p>
  <p>email: me@bassjacob.com</p>
</section>|j};

let render {title, subtitle, content} => {
  {j|<!doctype html>
<html>
  <head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">

    <title>$(title)</title>

    <link rel="stylesheet" href="/public/presentations/css/reveal.css">
    <link rel="stylesheet" href="/public/presentations/css/black.css">
    <link rel="stylesheet" href="/public/presentations/css/prism-okaidia.min.css">

    <style>
      .slides {
        width: 90% !important;
      }

      section,
      section section {
        flex-direction: column;
        justify-content: center;
        align-items: center;
      }

      .slides>section:nth-child(1)>h1 {
        color: #fabbaf;
      }

      h1 {
        color: #afbbfa !important;
      }

      h2 {
        color: #baffab !important;
      }

      .reveal > pre:only-of-type {
        width: 100% !important;
      }

      .reveal pre {
        border: 2px solid #f0f5f2;
      }

      .reveal code {
        max-height: 90vh !important;
      }

      aside.content {
        display: none;
      }
    </style>
  </head>
  <body>
    <div class="reveal">
      <div class="slides">
        <section>
          <h1>$(title)</h1>
          <div style="position:absolute; z-index: 2; top: 100%; right: 1%;">
            <a href="https://bassjacob.com">bassjacob.com</a>
          </div>
          <div style="position:absolute; z-index: 2; width: 100%; top: 100%; text-align: center;">
            $(subtitle)
          </div>
          <div style="position:absolute; z-index: 2; top: 100%; left: 1%;">
            <a href="https://twitter.com/bassjacob">@bassjacob</a>
          </div>
        </section>
        $(content)
        $(whoamiSlide)
      </div>
    </div>

    <script src="/public/presentations/js/prism.min.js"></script>
    <script src="/public/presentations/js/prism-reason.js"></script>
    <script src="/public/presentations/js/prism-javascript.js"></script>
    <script src="/public/presentations/js/prism-jsx.js"></script>
    <script src="/public/presentations/js/prism-haskell.js"></script>
    <script src="/public/presentations/js/prism-ocaml.js"></script>

    <script src="/public/presentations/js/head.min.js"></script>

    <script src="/public/presentations/js/reveal.js"></script>

    <script>
      Reveal.initialize({
        display: 'flex',
        history: true,
        width: "70%",
        transition: 'none',
        controls: false,
        slideNumber: 'v/h',
        showSlideNumber: 'speaker',
        dependencies: [
          { src: '/public/presentations/js/notes.js', async: true },
        ]
      });
    </script>
  </body>
</html>
  |j}
};
