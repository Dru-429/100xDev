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
 

//GET for fetching all notes
app.get('/notes', (req, res) =>{
  res.json({
   notes
  });
});

//GET for frontend 
app.get('/', (req, res) => {
  res.sendFile("C:/Users/RANIYA SAHOO/OneDrive/Deskop/dru.env/100xDev/webDev/week9/notes-app/frotnend/index.html");
})

app.listen(3000)