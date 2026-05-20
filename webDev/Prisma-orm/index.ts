import { Pool } from "pg";
import { PrismaClient } from "./generated/prisma/client";
import { PrismaPg } from "@prisma/adapter-pg";

const pool = new Pool({
  connectionString: process.env.DATABASE_URL
});

const adapter = new PrismaPg(pool);

const client = new PrismaClient({adapter});

async function createUser() {
  await client.user.create({
    data: {
      username: "Dhruv",
      password: "asd123123",
      age: 21,
      city: "Delhi"
    }
  })
}

createUser()