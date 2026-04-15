const mongoose = require('mongoose');
const url = process.env.MONGOOSE_URL;

mongoose.connect(MongooseU)

const userSchema = mongoose.Schema({
  "username": String,
  "password": String,
})

const todoSchema = mongoose.Schema({
  "title": String,
  "description": String,
  "done": false,
  "userId": mongoose.Types.ObjectId
})

const userModel = mongoose.model("users", userSchema);
const todoModel = mongoose.model("todos", todoSchema)

module.exports({
  userModel: userModel,
  todoModel: todoModel
})