-- CreateEnum
CREATE TYPE "Role" AS ENUM ('User', 'Assistant');

-- CreateTable
CREATE TABLE "Convo" (
    "id" TEXT NOT NULL,
    "initialPrompt" TEXT NOT NULL,

    CONSTRAINT "Convo_pkey" PRIMARY KEY ("id")
);

-- CreateTable
CREATE TABLE "Message" (
    "id" TEXT NOT NULL,
    "role" "Role" NOT NULL,
    "convoId" TEXT NOT NULL,

    CONSTRAINT "Message_pkey" PRIMARY KEY ("id")
);

-- CreateIndex
CREATE UNIQUE INDEX "Convo_id_key" ON "Convo"("id");

-- CreateIndex
CREATE UNIQUE INDEX "Message_id_key" ON "Message"("id");

-- AddForeignKey
ALTER TABLE "Message" ADD CONSTRAINT "Message_convoId_fkey" FOREIGN KEY ("convoId") REFERENCES "Convo"("id") ON DELETE RESTRICT ON UPDATE CASCADE;
