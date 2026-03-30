// http server tgat supports 4 routes (.sum, /sub, /div, /mul)

const express = require('express')

const app = express();

app.use(express.json)

//One req ko only send one res., to send more to one req we use envent stream that what chatgpt uses 
//Query param: http://localhost:3000/sum?a=1&b=2
//path param: http://localhost:3000/1/2  {Dynamiic Params}

app.get("/", function(req, res){
 res.sendFile(__dirname + "/index.html"); 
})

app.get("/sum/:a/:b", function(req, res) {
  //http://localhost:3000/sum?a=1&b=2
  // const a = parseInt(req.query.a); //string
  // const b = parseInt(req.query.b); //string so '1'  + '1' = 11
  
  //Path params:
  const a = parseInt(req.params.a); //string
  const b = parseInt(req.params.b); //string so '1'  

  const sum = a + b;
   
  res.json ({
    ans: sum
  })

});

//POST
app.post("/mul", function(req, res) {
  const a = parseInt(req.body.a); //string
  const b = parseInt(req.body.b); //string so '1'  

  const sum = a * b;
  res.send(sum.toString());
});


app.get("/sub");
app.get("/div");

app.listen(3000, () => {
  console.log("Server started on port 3000");
});