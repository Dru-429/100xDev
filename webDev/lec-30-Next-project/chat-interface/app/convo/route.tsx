import { prisma } from "@/lib/db";
import { NextRequest } from "next/server";

export async function POST(req: NextRequest) {
  const body = await req.json()
  const db_resp = await prisma.convo.create({
    data: {
      initialPrompt: body.initialPrompt
    }
  })

  await prisma.message.create({
    data: {
      convoId: db_resp.id,
      message: body.initialPrompt, 
      role: "User"
    }
  })

  return Response.json({ message: "New Convo Added", id: db_resp.id})
}

export async function GET(req: NextRequest) {
  const id = req


  return Response.json({ message: "GET req recived"})
}