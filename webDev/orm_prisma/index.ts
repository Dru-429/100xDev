import { Pool } from "pg";
import { PrismaPg } from "@prisma/adapter-pg";
import { PrismaClient } from "./generated/prisma/client";
import express, { Express } from "express";

const app: Express = express();

const pool = new Pool({
  connectionString: process.env.DATABASE_URL,
});

const adapter = new PrismaPg(pool);
const client = new PrismaClient({ adapter });

async function createUser() {
  const newUser = await client.user.create({
    data: {
      name: "Dhruv",
      password: "asd123123",
      age: 21,
      city: "Delhi",
    },
  });
  console.log("User created successfully:", newUser);
}

async function fetchTodos() {
  const todos = await client.user.findMany({
    where: {
      id: 1
    },
    include: {
      todos: true
    }
  });
  console.log("User todo fetched successfully:", todos);
}

fetchTodos()