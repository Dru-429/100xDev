import { Pool } from "pg";
import { PrismaPg } from "@prisma/adapter-pg";
import { PrismaClient } from "@prisma/client/extension";

const pool = new Pool({
  connectionString: process.env.DATABASE_URL,
});

const adapter = new PrismaPg(pool);
const client = new PrismaClient({ adapter });

async function createUser() {
  const newUser = await client.user.create({
    data: {
      username: "Dhruv",
      password: "asd123123",
      age: 21,
      city: "Delhi",
    },
  });
  console.log("User created successfully:", newUser);
}

createUser();