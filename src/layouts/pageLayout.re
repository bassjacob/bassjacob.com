type page = {
  title: string,
  content: string
};

let render {title, content} => {
  {j|<div class="page">
  <h1 class="page-title">$(title)</h1>
  $(content)
</div>
  |j}
};
