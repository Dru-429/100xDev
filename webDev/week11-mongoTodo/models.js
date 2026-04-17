const mongoose = require('mongoose');

mongoose.connect("")

//mongoose Schema and model objects
const userSchema = new mongoose.Schema({
  username: String,
  password: String,
});

const todoSchema = new mongoose.Schema({
  title: String,
  description: String,
  userId: mongoose.Types.ObjectId,
});

const userModel = mongoose.model("users", userSchema);
const todoModel = mongoose.model("todos", todoSchema);

module.exports = {
  todoModel: todoModel,
  userModel: userModel,
};