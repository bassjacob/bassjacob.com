type post = { title: string, date: string, content: string, url: string };
type locals = { posts: array post };

let makePost {title, content, url, date} => {
  {j|<div class="post">
  <h1 class="post-title">
    <a href="/posts/$(url)">
      $(title)
    </a>
  </h1>

  <span class="post-date">$(date)</span>

  $(content)
</div>
  |j}
};

let render (locals: locals) => {
  let posts = Js.Array.joinWith "" (Array.map makePost locals.posts);
  {j|<div class="posts">
  $(posts)
</div>
  |j}
};
