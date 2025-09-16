const express = require("express")
const app = express()

app.get("/params/:name", function(req, res) {
    const name = req.params.name;
    console.log(name);
    res.send("name of the file is" + name )
})

app.listen(3001)