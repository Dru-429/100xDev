const express = require("express");
const { Pool }  = require("pg");
const jwt = require("jsonwebtoken")
const { authMiddleware } = require("./middelware")
const bcrypt = require("bcrypt")
const z = require('zod');

const pool = new Pool({
  connectionString: "postgresql://neondb_owner:npg_4kMImde5couG@ep-damp-pine-anq6eyou-pooler.c-6.us-east-1.aws.neon.tech/neondb?sslmode=require&channel_binding=require"
});

const app = express();
app.use(express.json());

const signupSchema = z.object({
  username: z.string().min(3),
  password: z.string().min(6),
  email: z.email(),
})

//signup
app.post("/signup", async (req, res) => {
  // const { username, email, password } = req.body;
  const { data, success, error} = signupSchema.safeParse(req.body);

  if(!success) {
    res.status(403).json({
      message: "incourrect inputs",
      error: JSON.parse(error)
    })
    return
  }

  const username = data.username;
  const password = data.password;
  const email = data.email;

  const hashedPassword = await bcrypt.hash(password, 10);

  console.log('INSERT INTO users (username, email, password) VALUES ($1, $2, $3)', [username, email, hashedPassword]);
  const response = await pool.query('INSERT INTO users (username, email, password) VALUES ($1, $2, $3) RETURNING id;', [username, email, hashedPassword]);

  console.log(response);
  res.json({
    // userId: users.rows[0].id,
    message: "User added succesfully"
  })
})

//signin
app.post("/signin", async (req, res) => {
  const { email, password } = req.body;

  const response = await pool.query('SELECT * FROM users WHERE email = ($1);', [email])

  // console.log(response);
  const userExits = response.rows[0];

  if(!userExits) {
    res.status(403).json({
      message: "Incorrect "
    })
  }
  else{
    const correctPassword = await bcrypt.compare(password, userExits.password)

    if(correctPassword) {
      const token = jwt.sign({
        userId: userExits.id
      }, "sqltodo123123")
  
      res.json({
        token
      })
    }
    else{
      res.status(403).json({
        message: "Incorrect cerds"
      })
    }
  }

})

//add todo
app.post("/todo", authMiddleware, async (req, res) => {
  const userId = parseInt(req.userId);
  const { title, description } = req.body;

  const response = await pool.query("INSERT INTO todos (title, description, done, user_id ) VALUES ($1, $2, FALSE, $3) RETURNING ID;", [title, description, userId] )
  console.log("INSERT INTO todos (title, description, done, user_id ) VALUES ($1, $2, FALSE, $3) RETURNING ID;", [title, description, userId] )
  console.log(response); 

  res.json({
    message: "Todo added Seccesfully"
  })
})
 
//mark done
app.put("/todo/:todoId", authMiddleware,async (req, res) => {
  const userId = parseInt(req.userId);
  const todoId = parseInt(req.params.todoId);

  const response = await pool.query(' UPDATE todos SET done = TRUE WHERE id = ($1) AND user_id = ($2) RETURNING ID;', [todoId, userId]);
  console.log(response);

  res.json({
    message: "Todo marked as done"
  })
})

//delete todo
app.delete("/todo/:todoId", authMiddleware, async (req, res) => {
  const userId = parseInt(req.userId);
  const todoId = parseInt(req.params.todoId);

  const response = await pool.query('DELETE FROM todos WHERE id = ($1) AND user_id = ($2) RETURNING ID;', [todoId, userId]);
  console.log(response);

  res.json({
    message: "Todo deleted successfully"
  })
})

//get all todos
app.get("/todo", authMiddleware, async (req, res) => {
  const userId = parseInt(req.userId);

  const response = await pool.query("SELECT * FROM todos WHERE user_id = ($1);", [userId]);
  console.log("SELECT * FROM todos WHERE user_id = ($1);", [userId]);
  console.log(response);

  res.json({
    todos: response.rows[0]
  })
})

app.listen(3000, () => {
  console.log("Server is running on port 3000");
})