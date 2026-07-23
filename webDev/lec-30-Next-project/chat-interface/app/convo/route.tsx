import { NextRequest } from "next/server";

export async function POST(req: NextRequest) {
  const prompt = await req.json()
  

  return Response.json({ message: "Post req recived"})
}

export async function GET() {
  return Response.json({ message: "GET req recived"})
}