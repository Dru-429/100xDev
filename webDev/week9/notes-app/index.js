const express = require('express');

const app = express();

const notes = [];  //In memory DB for now 
app.use(express.json());  //Middleware to parse JSON body of requests


//POST for creating a notes
app.post('/notes', (req, res) => {
  const notes = req.body.note;
  notes.push(notes);

  res.json({
    message: "done"
  });
});

//POST for sign in
app.post("/signup", (req, res)=> {
  const username = req.body.username;
  const password = req.body.password;
  const useExists = users.find (user => user.username === username);
  
})


//GET for fetching all notes
app.get('/notes', (req, res) =>{
  res.json({
   notes
  });
});

//GET for frontend 
app.get('/', (req, res) => {
  res.sendFile("index.html", {root: __dirname});
})

app.listen(3000)
