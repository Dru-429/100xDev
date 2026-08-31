FROM ubuntu:latest

RUN curl -fsSL https://bun.com/install | bash

WORKDIR /app
COPY . .

RUN bun install 

CMD ["bum", "/app/index.ts"]


