type url = {
  location: string,
  changeFreq: string,
  priority: string,
};

let renderUrl ({location, changeFreq, priority}: url): string => {
  {j|<url>
  <loc>$(location)</loc>
  <changefreq>$(changeFreq)</changefreq>
  <priority>$(priority)</priority>
</url>
  |j};
};

let render (urls: array url): string => {
  let urlMaps = Array.map renderUrl urls |> Js.Array.joinWith "\n";

  {j|<?xml version="1.0" encoding="UTF-8"?>
<urlset xmlns="http://www.sitemaps.org/schemas/sitemap/0.9">
  $(urlMaps)
</urlset>
  |j}
};
