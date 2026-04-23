const jwt = require("jsonwebtoken")

function authMiddleware(req, res, next ) {
  const token = req.headers.token;

  const decoded = jwt.verify(token, "sqltodo123123");
  const user = decoded.userId;

  if(user) {
    req.userId = user;
    next();
  }
  else{
    res.status(403).json({
      message: "Unauthorized"
    })
    return
  }
}

module.exports = ({
  authMiddleware: authMiddleware
})