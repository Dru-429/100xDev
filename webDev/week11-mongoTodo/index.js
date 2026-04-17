const express = require('express');
const { authMiddleware } = require('./middleware');
const jwt = require('jsonwebtoken');
const { userModel, todoModel } = require('./models');

const app = express();
app.use(express.json());

app.post('/signup', async (req, res) => {
  const { username, password } = req.body;
  
  const existingUser = await userModel.findOne({
    username: username,
    password: password,
  });

  if(existingUser){
    res.status(403).json({
      message: "User already exists"
    })
    return;
  }
  const newUser = await userModel.create({
    username: username,
    password: password,
  })

  res.json({
    id: newUser._id
  })
})

app.post('/signin', async (req, res) => {
  const username = res.body.username;
  const password = req.body.password;

  const userExits = await userModel.findOne({
    username: username,
    password: password,
  })

  if(!userExits){
    res.status(403).json({
      message: "Invalid username or password"
    })
  }

  const token = jwt.sign({
    userId: userExits.userId
  }, "secret123123");

  res.send({
    token
  })
})

app.post('/todo', authMiddleware, (req, res) => {
  const userId = req.userId;

  const { title, discription } = req.body;

  TODOS.push([
    id,
    title,
    discription,
    userId,
  ])

  res.json({
    message: "Todo created successfully"
  })

})

app.delete('/todo/:todoId', authMiddleware, (req, res) => {
  const userId = req.userId;
  const todoId = parseInt(req.params.todoId);

  const doseUserOwnTodo = TODOS.find(t => t.id === todoId && t.userId === userId);

  if(doseUserOwnTodo){
    TODOS = TODOS.filter(t => t.id !== todoId);
    
    res.json({
      message: "Todo deleted successfully"
    });
  }
  else {
    res.status(403).json({
      message: "Todo not found or you don't have permission to delete this todo"
    })
  }
})

app.get('/todos', authMiddleware, (req, res) => {
  const userId = req.userId;
  const userTodos = TODOS.filter(t => t.userId === userId);

  res.json({
    todos: userTodos
  })
})


app.listen(3000, () => {
    console.log('Server is running on port 3000');
})