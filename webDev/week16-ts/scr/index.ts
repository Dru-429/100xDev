import express from "express";

const app = express();
app.use(express.json());

interface SignupInput {
  username: string;
  password: string;  
  address: {
    city: string;
    state: string;  
  }
}

app.post("/signup", (req, res) => {
  const body: SignupInput = req.body; 

})