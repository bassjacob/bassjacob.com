let render _ => {
  let homeUrl = "/";
  {j|
<div class="page">
  <h1 class="page-title">404: Page not found</h1>
  <p class="lead">
    Sorry, we've misplaced that URL or it's pointing
    to something that doesn't exist.
    <a href="$(homeUrl)">Head back home</a> to try finding it again.
  </p>
</div>
  |j}
};
