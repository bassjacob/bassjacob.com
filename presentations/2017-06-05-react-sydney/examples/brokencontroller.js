module.exports = function (req, res, next) {
  if (req.sendOne) {
    res.send('1');
  } else if (req.sendTwo) {
    res.send('2');
  }
};
