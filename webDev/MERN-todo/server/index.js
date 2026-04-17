const express = require('express')
const { userModel, todoModel} = require("./models")
const jwt = require("jsonwebtoken")
const { authmiddleware } = require('./middleware')

const app = express();
app.use(express.json);

//singup
app.post('/signup', async (req, res) => {
  const { user, password } = req.body;

  const userExits = await userModel.findOne({
    username: user,
    password: password
  })

  if(userExits){
    res.status(403).json({
      message: "User already exits"
    })
    return
  }

  const newUser = await userModel.create({
    username: user,
    password: password
  })

  res.send({
    message: "User created successfully",
    id: newUser._id
  })
})

//signin
app.post('/signin', async (req, res) => { 
  const { user, password } = req.body;

  const userExits = await userModel.findOne({
    username: user,
    password: password
  });

  if(!userExits){
    res.status(403).json({
      message: "User not found",
    })
    return;
  }

  const token = jwt.sign({
    userId: userExits._id
  }, "secret123123");

  res.send({
    token
  })
})

//psot todos to the db
app.post('/todo', authmiddleware, async (req, res) => {
  const title = req.body.title;
  const description = req.body.description;
  const userId = req.userId;

  const newTodo = await todoModel.create({
    "userId": userId,
    "title" : title,
    "description": description,
    "done": false
  })

  res.send({ 
    message: "todo list updated",
    id: newTodo._id
  })
})

//get all todods
app.get('/todo', authmiddleware, async (req, res) => {
  const userId = req.userId;
  
  const todos = await todoModel.find({
    userId: userId
  })

  res.json({
    todos: todos,
  })
})

//done
app.post("/todo/:todoId", authmiddleware, async (req, res) => {
  const userId = req.userId;
  const todoId = req.params.todoId;

  await todoModel.updateOne({
    _id: todoId,
    userId: userId
  }, {
    done: true
  })

  res.json({
    message: "Updated succesfully"
  })    
})

//delete todo
app.delete("/todo/:todoId", authmiddleware, async (req, res)=> {
  const userId = req.userId;
  const todoId = req.params.todoId

  await todoModel.delete({
    _id: todoId,
    "userId": userId
  })

  res.json({
    message: "todo deleted succesfully "
  })
})


app.listen(3000, () => {
  console.log("Server started at port 3000")
})