window.onload = window.onpopstate = function (event) {
  const slides = document.querySelectorAll('section');
  const query = document.location.search.slice(1).split('&').filter(q => q !== "").reduce((queries, query) => { const [key, value] = query.split('='); queries[key] = value || true; return queries; }, {});
  let currentSlide = query.page = (event && event.state && event.state.page) || parseInt(query.page || '0');

  function goToSlide () {
    slides.forEach(function (slide, index) {
      if (index === currentSlide) {
        if (slide.querySelectorAll('section').length > 0) {
          return nextSlide();
        }

        slide.classList.remove('hidden');
        slide.classList.add('active');

        if (slide.parentNode.nodeName === 'SECTION') {
          slide.parentNode.classList.remove('hidden');
          slide.parentNode.classList.add('active');
        }

        const codes = slide.querySelectorAll('code');
        codes.forEach(code => {
          const marks = code.querySelectorAll('mark');

          if (marks.length === 0) {
            hljs.highlightBlock(code);
          } else {
            code.style.color = 'grey';
            marks.forEach(mark => {
              hljs.highlightBlock(mark);
            });
          }
          textFit(code);
        });
        return;
      }

      slide.classList.add('hidden');
      slide.classList.remove('active');

      return;
    });
  }

  function onSlideEnter() {
    query.page = currentSlide;
    const search = '?' + Object.keys(query).map(key => `${key}=${query[key]}`).join('&')
    const url = `${document.location.origin}${document.location.pathname}${search}`;
    history.pushState(query, document.title, url);
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

  goToSlide();
}
