const express = require('express');
const jwt = require('jsonwebtoken')

const app = express();

app.use(express.json());  //Middleware to parse JSON body of requests
const notes = [];  //In memory DB for now 
const users = [{
  username: "dru429",
  password: "123123"
}];

app.post('/signup', function(req, res){
  const username = req.body.username;
  const password = req.body.password;
  const userExists = users.find(user => user.username === username);
  if(userExists){
    return res.status(403).json({
      message: "User with this username already exists"
    })
  }

  users.push({
    username, password
  })

  res.json({
    message: "User signed up"
  })
})


app.post('/signin', function(req, res){
  const username = req.body.username;
  const password = req.body.password;
  const userExists = users.find(user => user.username === username && user.password === password);

  if(userExists){
    res.status(403).json({
      message: "Wrong ID or Password"
    })
  }

  //jwt json web tokens
  const token = jwt.sign({
    username: username
  }, "dru429");
  res.json({
    token
  })
})

//POST for creating a notes - AUTHENTICATION ENDPOINT
app.post('/notes', (req, res) => {

  //CHECK IF THEY HAD THE RIGHT HEADER and extraxt who is this user 
  const token = req.headers.token;

  if(!token){
    res.status(403).send({
      message: "You r not looged in"
    })
  }

  const decoded = jwt.verify(token, "dru429");
  const username = decoded.username;

  if(!username){
    res.status(403).send({
      message: "Malfunction token"
    })
  }

  const note = req.body.note;
  notes.push(note);

  res.json({
    message: "done"
  });
});
 

//GET for fetching all notes - AUTHENCATED ENDPOINT
app.get('/notes', (req, res) =>{
  const token = req.header.token;

  if(!token) {
    res.status(403).send({
      message: "You r not logged in"
    })
  }
   
  const decode = jwt.verify(token, "dru429");
  const username = decode.username;

  if(!username){
    res.status(403).send({
      meassage: "Malfunction token"
    })
  }

  const userNotes = notes.map(note => note.username === username);
  res.json({
   userNotes
  });
});

//GET for frontend 
app.get('/', function(req, res) {
  res.sendFile(__dirname + '/frontend/index.html');
})

app.listen(3000, () => {
  console.log("Server is running on port 3000");
})