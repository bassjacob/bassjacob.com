window.onload = window.onpopstate = function (event) {
  const slides = document.querySelectorAll('section');
  const query = document.location.search.slice(1).split('&').filter(q => q !== "").reduce((queries, query) => { const [key, value] = query.split('='); queries[key] = value || true; return queries; }, {});
  let currentSlide = query.page = parseInt(query.page || '0');

  function goToSlide () {
    slides.forEach(function (slide, index) {
      if (index === currentSlide) {
        return slide.classList.remove('hidden');
      }

      return slide.classList.add('hidden');
    });
  }

  function onSlideEnter() {
    query.page = currentSlide;
    const search = '?' + Object.keys(query).map(key => `${key}=${query[key]}`).join('&')
    history.pushState(query, document.title, `${document.location.origin}${document.location.pathname}${search}`);
    goToSlide();
  }

  function nextSlide() {
    if (currentSlide + 1 === slides.length) return;
    currentSlide += 1;
    onSlideEnter();
  }

  function previousSlide() {
    if (currentSlide === 0) return;
    currentSlide -= 1;
    onSlideEnter();
  }

  document.onkeydown = function (event) {
    if (event.code === 'Space') {
      if (event.shiftKey) {
        return previousSlide();
      }

      return nextSlide();
    } else if (event.code === 'PageDown') {
      return nextSlide();
    } else if (event.code === 'PageUp') {
      return previousSlide();
    }
  }

  currentSlide = (event && event.state && event.state.page) || 0;
  goToSlide();
}

hljs.initHighlightingOnLoad();
