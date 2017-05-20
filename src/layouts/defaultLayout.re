type locals = { title: string, content: string };

let siteTitle = "Code, Coffee and CLI's";
let siteTagline = "";
let siteDescription = "";

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

    <meta name="viewport" content="width=device-width, initial-scale=1.0, maximum-scale=1">

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
  </head>

  <body>
    <input type="checkbox" class="sidebar-checkbox" id="sidebar-checkbox">

    <div class="sidebar" id="sidebar">
      <nav class="sidebar-nav">
        <a class="sidebar-nav-item" href="/">Home</a>
        <div class="sidebar-nav-item">
          <img src="/public/avatar.jpg"></img>
          <div class="sidebar-item">
            <p>$(siteDescription)</p>
          </div>
        </div>
        <a class="sidebar-nav-item" href="/about">About</a>
        <a class="sidebar-nav-item" href="/talks">Talks</a>
        <a class="sidebar-nav-item" href="/posts">Posts</a>
        <a class="sidebar-nav-item" href="/resume">Resume</a>
      </nav>

      <div class="sidebar-item">
        &copy; 2017. All rights reserved.
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
        var toggle = document.querySelector('.sidebar-toggle');
        var sidebar = document.querySelector('#sidebar');
        var checkbox = document.querySelector('#sidebar-checkbox');

        document.addEventListener('click', function(e) {
          var target = e.target;

          if(!checkbox.checked ||
             sidebar.contains(target) ||
             (target === checkbox || target === toggle)) return;

          checkbox.checked = false;
        }, false);
      })(document);
    </script>
  </body>
</html>
  |j}
};
