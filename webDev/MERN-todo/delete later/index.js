const express = require(express);

const app = express();

app.use(express.json());

//sign up 
app.post("/signup", (req, res) => {
  const username = req.body.username;
  const password = req.body.password;

  const userEixts = "";

  if(userEixts){
    res.send(403).json({
      message: "users already exits"
    })
    return
  }

  userModel.push({
    "username": username,
    "password": password
  })

  res.json({
    message: "New user created successfully"
  })

})

//signin
app.post("/signin", (req, res) => {
  const { username, password } = req.body;

  const userExits = "";

  if(!userExits){
    res.send(403).json({
      message: "wrong user credencial"
    })
  }

  const token = jwt.sign({
    userId: userExits._id
  }, "dru123123")

  res.send({
    token: token,
    message: "Logged in"
  })
})

//Create Todo
app.post("/todo", async( req, res) => {

})

//Get all todos
app.get("/todos", async (req, res) => {

})

//mark done a todo
app.post("/todo/:todoId", (req, res) => {

})

// Delete todo
app.post("/todos/:todoId", (req, res) => {

})

app.listen(3000)