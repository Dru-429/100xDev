const jwt = require("jsonwebtoken");

function authmiddleware (req, res, next) {
  const token = req.headers.token;
  const decoded = jwt.verify(token, "secret123123");
  const user = decoded.userId;

  if(user){
    req.userId = user;
    next()
  }
  else {
    res.status(403).json({
      message: "Invalide Token",
    })
  }
}

module.exports = {
  authmiddleware: authmiddleware,
}