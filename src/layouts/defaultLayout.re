type locals = { title: string, content: string };

let siteTitle = "Code, Coffee and CLI's";
let siteTagline = "Occasional musings on software, through software.";
let siteDescription = "Hi, I'm Jacob. Very occasionally I convince myself to write something here, but far more often I go and build something else instead.";

let makeLocals ::title=siteTitle ::content="" () => {
  { title, content };
};

let render (locals: locals) () => {
  let title = locals.title;
  let content = locals.content;

  {j|<!DOCTYPE html>
<html lang="en-us">
  <head>
    <link href="http://gmpg.org/xfn/11" rel="profile">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta http-equiv="content-type" content="text/html; charset=utf-8">

    <meta name="viewport" content="width=device-width, initial-scale=1.0">

    <title>
      $(title)
    </title>

    <link rel="stylesheet" href="/public/css/poole.css">
    <link rel="stylesheet" href="/public/css/syntax.css">
    <link rel="stylesheet" href="/public/css/lanyon.css">
    <link rel="stylesheet" href="https://fonts.googleapis.com/css?family=PT+Serif:400,400italic,700%7CPT+Sans:400">

    <link rel="apple-touch-icon-precomposed" sizes="144x144" href="/public/apple-touch-icon-precomposed.png">
    <link rel="shortcut icon" href="/public/favicon.ico">

    <link rel="alternate" type="application/rss+xml" title="RSS" href="/atom.xml">
    <style>
      div.post hr {
        border-top: 2px solid #aaa;
      }

      div.post > section {
        display: flex;
        flex-direction: column;
        justify-content: center;
        align-items: center;
        width: 100%;
      }

      div.post > section > section > div > img {
        width: 100%;
      }

      div.post section > * {
        width: 100%;
      }

      div.post pre {
        overflow: scroll;
        white-space: pre;
      }

      div.post > section > section > * {
        border: solid 1px black;
        padding: 5px;
        text-align: center;
      }

      div.post > section > section > div > pre {
        border: solid 1px black;
        padding: 5px;
        text-align: initial;
      }

      div.post > section > section > pre {
        text-align: left;
        padding: 30px;
      }

      div.post > section > section > aside {
        margin: 10px 0;
        border: none;
        padding: 0;
        text-align: left;
      }

      aside.notes {
        display: none;
      }

      div.post pre.inline-pre {
        display: inline;
        padding: 0 0.5rem;
        margin: 0;
        color: red;
      }
    </style>
  </head>

  <body>
    <input type="checkbox" class="sidebar-checkbox" id="sidebar-checkbox">

    <div class="sidebar" id="sidebar">
      <nav class="sidebar-nav">
        <div class="sidebar-nav-item">
          <img style="border-radius: 100%" src="/public/avatar.jpg"></img>
          <div class="sidebar-item" style="padding: 0">
            <p>$(siteDescription)</p>
          </div>
        </div>
        <a class="sidebar-nav-item" href="/">Home</a>
        <a class="sidebar-nav-item" href="/about">About</a>
        <a class="sidebar-nav-item" href="/talks">Talks</a>
        <a class="sidebar-nav-item" href="/posts">Posts</a>
        <a class="sidebar-nav-item" href="/resume">Resume</a>
        <div class="sidebar-nav-item">
          <p>Elsewhere</p>
          <ul>
            <li><a href="https://github.com/bassjacob">github</a></li>
            <li><a href="https://twitter.com/bassjacob">twitter</a></li>
            <li><a href="https://linkedin.com/in/bassjacob">linkedin</a></li>
            <li><a href="mailto:bassjacob@gmail.com">email</a></li>
          </ul>
        </div>
      </nav>

      <div class="sidebar-item">
        <p>Themes</p>
        <div class="themes">
          <div data-theme-class="theme-base-00" class="theme-box theme-base-00"></div>
          <div data-theme-class="theme-base-08" class="theme-box theme-base-08"></div>
          <div data-theme-class="theme-base-09" class="theme-box theme-base-09"></div>
          <div data-theme-class="theme-base-0b" class="theme-box theme-base-0b"></div>
          <div data-theme-class="theme-base-0c" class="theme-box theme-base-0c"></div>
          <div data-theme-class="theme-base-0d" class="theme-box theme-base-0d"></div>
          <div data-theme-class="theme-base-0e" class="theme-box theme-base-0e"></div>
          <div data-theme-class="theme-base-0f" class="theme-box theme-base-0f"></div>
        </div>
      </div>

      <div class="sidebar-item">
        With thanks to <a href="https://twitter.com/mdo">@mdo</a> for the <a href="http://lanyon.getpoole.com/">lanyon theme</a>.
      </div>
    </div>

    <div class="wrap">
      <div class="masthead">
        <div class="container">
          <h3 class="masthead-title">
            <a href="/" title="Home">$(siteTitle)</a>
            <small>$(siteTagline)</small>
          </h3>
        </div>
      </div>

      <div class="container content">
        $(content)
      </div>
    </div>

    <label for="sidebar-checkbox" class="sidebar-toggle"></label>

    <script>
      (function(document) {
        var body = document.querySelector('body');
        var toggle = document.querySelector('.sidebar-toggle');
        var sidebar = document.querySelector('#sidebar');
        var checkbox = document.querySelector('#sidebar-checkbox');
        var themes = document.querySelectorAll('.theme-box');

        document.addEventListener('click', function(e) {
          var target = e.target;

          if(target.classList.contains('theme-box')) {
            body.classList.forEach(function(c) { body.classList.remove(c); });
            body.classList.add(e.target.dataset.themeClass);
            return;
          } else if(!checkbox.checked || sidebar.contains(target) || target === checkbox || target === toggle) {
            return;
          }

          checkbox.checked = false;
        }, false);
      })(document);
    </script>
    <script>
      if (!window.location.origin.match(/localhost/)) {
        (function(i,s,o,g,r,a,m){i['GoogleAnalyticsObject']=r;i[r]=i[r]||function(){
        (i[r].q=i[r].q||[]).push(arguments)},i[r].l=1*new Date();a=s.createElement(o),
        m=s.getElementsByTagName(o)[0];a.async=1;a.src=g;m.parentNode.insertBefore(a,m)
        })(window,document,'script','https://www.google-analytics.com/analytics.js','ga');

        ga('create', 'UA-58416048-2', 'auto');
        ga('send', 'pageview');
      }
    </script>
  </body>
</html>
  |j}
};
