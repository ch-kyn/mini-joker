FROM ubuntu:24.04

RUN apt update && apt install -y \
    clang \
    make \
    libutf8proc-dev \
    nodejs \
    npm \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

COPY . .

RUN make mini-joker

WORKDIR /app/web

RUN npm install

EXPOSE 3000

CMD ["node", "server.js"]