const express = require("express");
const { Pool }  = require("pg");
const jwt = require("jsonwebtoken")
const { authMiddleware } = require("./middelware")

const pool = new Pool({
  connectionString: "postgresql://neondb_owner:npg_4kMImde5couG@ep-damp-pine-anq6eyou.c-6.us-east-1.aws.neon.tech/neondb?sslmode=require"
});

const app = express();
app.use(express.json());

//signup
app.post("/signup", async (req, res) => {
  const { username, email, password } = req.body;

  console.log('INSERT INTO users (username, email, password) VALUES ($1, $2, $3)', [username, email, password]);
  const response = await pool.query('INSERT INTO users (username, email, password) VALUES ($1, $2, $3) RETURNING id;', [username, email, password]);

  console.log(response);
  res.json({
    userId: user.rows[0].id,
    message: "User added succesfully"
  })
})

//signin
app.post("/signin", async (req, res) => {
  const { email, password } = req.body;

  //VERY BAD WAY TO WRITE CUZZ IT CAUSE SQL INJECTION SO USE THE 
  // const response = await pool.query(`SELECT * FROM users WHERE email='${email}' AND password='${password}';`);
  const response = await pool.query('SELECT * FROM users WHERE email = ($1) AND password = ($2);', [email, password])
  console.log('SELECT * FROM users WHERE email = "($1)" AND password = "($2)";' [email, password] )

  // console.log(response);
  const userExits = response.rows[0];

  if(!userExits) {
    res.status.json({
      message: "Incorrect "
    })
  }
  else{
    const token = jwt.sign({
      userId: userExits.id
    }, "sqltodo123123")

    res.json({
      token
    })
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

})

//delete todo
app.delete("/todo/:todoId", authMiddleware, async (req, res) => {

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