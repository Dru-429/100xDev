const express = require("express");
const { Pool }  = require("pg");
const jwt = require("jsonwebtoken")

const pool = new Pool({
  connectionString: "postgresql://neondb_owner:npg_4kMImde5couG@ep-damp-pine-anq6eyou.c-6.us-east-1.aws.neon.tech/neondb?sslmode=require"
});

const app = express();
app.use(express.json());

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

app.post("/signin", async (req, res) => {
  const { email, password } = req.body;

    //VERY BAD WAY TO WRITE CUZZ IT CAUSE SQL INJECTION SO USE THE 
  const response = await pool.query(`SELECT * FROM users WHERE email='${email}' AND password='${password}';`);
  console.log(`SELECT * FROM users WHERE email='${email}' AND password='${password}';`);
  console.log(response);

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


app.listen(3000, () => {
  console.log("Server is running on port 3000");
})