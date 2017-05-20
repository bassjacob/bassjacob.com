type post = {
  title: string,
  date: string,
  content: string,
};

let render {title, date, content} => {
  {j|<div class="post">
<h1 class="post-title">$(title)</h1> <span class="post-date">$(date)</span>
  $(content)
</div>
  |j}
};
