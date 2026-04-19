const express = require("express");
const jwt = require("jsonwebtoken");

const app = express();

app.use(express.json())

const USER_ID = 1;
const ORG_ID = 1;
const BOARD_ID = 1;
const IISUE_ID = 1;


//  DB structure
const USERS = [];
const ORGS = [{
  id: 1,
  title: "100xDevs",
  description: "Coding learning paltform",
  admin: 1,
  members: [2],
}, {
  id: 2,
  title: "Kirats org",
  description: "CLI to post about on X",
  admin: 2,
  members: [],
}];
const BOARDS = [{
  id: 1,
  title: "100XDevs frontend",
  organizaation: 1,
}];
const ISSUES = [{
  id: 1,
  title: "Add dark mode",
  boardid: 1, 
  state: "NEXT_UP"
}, {
  id: 2,
  title: "Allow admain to create more courses",
  boardid: 1,
  state: "IN_PROGRESS"
}];

//sign up
app.post("/signup", (req, res)=>{
  const { username, password } = req.body;
  
  const userExits =USERS.find( u => u.username === username );

  if(userExits){
    res.status(403).json({
      message: "User Already exits"
    })
  }

  USERS.pushK({
    username, 
    password, 
    id: USER_ID++
  })

  res.json({
    message: "User added"
  })

})

//signin
app.post("/signup", (req, res) => {
  const { username, password } = req.body;

  const userExits = USERS.find(u => u.username === username && u.password === password);

  if(!userExits) {
    res.status(403).json({
      message: "Incorrect credentials"
    })

    //create jwt
    const token = jwt.sign({
      userId: userExits.id, 
    }, "trello123123")

    res.json({
      token
    })
  }

})

//orgs
app.post("/organization", (req, res) => {

})

//adding members to the org 
app.post("/add-member-to-org", (req, res) => {

})

//create board 
app.post("/board", (req, res) => {

})

//create issue 
app.post("/issue", (req, res) => {

})

//Reading endpoints 

app.get("/boards", (req, res) => {

})

app.get("/issues", (req, res) => {

})

app.get("/members", (req, res) => {

})

//Move endpoint 
app.put("/issues/:issueId", (req, res) => {

})

//delete endpoint
app.delete("/members/:memberId", (req, res) => {

})


app.listen("3000", () => {
  console.log("Server started at port 3000")
})