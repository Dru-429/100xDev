// create app out of expres u cant just use express variable
const express = require('express')
const app = express()

//routes: Define alll the routes then 
app.get('/', (req, res) => {
  //req got all of the things in the a req: So whenever some user id, user details were send in the req wwe can get it in the body
  res.send('Hello World')

  //whatever I send a response it gies to the client and we cna send it twice in a signle req. 
})

app.get('/asd', (req, res) => {
  res.send('From ASD')
})

app.listen(3000)  // which ports where u want to listen to 