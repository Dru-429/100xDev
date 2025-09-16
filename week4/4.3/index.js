const express = require('express')
const app = express();
app.use(expree.json());

var users = [
  {
    name: "John",
    kidneys: [
      {
        healthy: false,
      },
    ],
  },
];

//Routes
//1. To check the status of user kidneys
app.get("/", function(req, res) {
    const johnsKidneys = users[0].kidneys;
    const numberOfKidneys = johnsKidneys.length;
    let numberOfHealthyKidneys = 0;

    for (let i = 0; i<johnsKidneys.length; i++){
        if (johnsKidneys[i].healthy) {
            numberOfHealthyKidneys = numberOfHealthyKidneys + 1;
        }
    }

    const numberOfUnhealthyKidneys = numberOfKidneys - numberOfHealthyKidneys

    res.json({
        johnsKidneys,
        numberOfKidneys, 
        numberOfHealthyKidneys,
        numberOfUnhealthyKidneys
    })
})

//2. To add a new kidneys
app.post("/", function(req, res) {
    const isHealthy = req.body.isHealthy;
    users[0].kidneys.push({
        healthy : isHealthy,
    });

    res.json({
        msg: "Done...!"
    });
})

//3.Update every kidney to be healthy
app.put("/", function(req,res) {
    for (let i=0; i<= users[0].kidneys; i++) {
        users[0].kidneys[i].healthy = true;
    }

    res.json({})
})

//4.User Can delete all their unhealthy kidneys
app.delete("/", function(req, res) {
    const newKidneys = [];
    for (let i=0; i<= users[0].kidneys; i++) {
       if (users[0].kidneys[i].healthy){
        newKidneys.push({
            healthy: true
        })
       };
    }
    users[0].kidneys = newKidneys;
    res.json({ msg: "done"})
})

app.listen(3000)