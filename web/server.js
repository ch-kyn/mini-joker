const express = require("express");
const http = require("http");
const WebSocket = require("ws");
const pty = require("node-pty");
const path = require("path");

const app = express();
app.use(express.static("public"));

const server = http.createServer(app);
const wss = new WebSocket.Server({ server });

const gamePath = path.resolve("../mini-joker");
const gameDir = path.resolve("..");

wss.on("connection", (ws) => {
const shell = pty.spawn(gamePath, [], {
    name: "xterm-256color",
    cols: 200,
    rows: 120,
    cwd: gameDir,
    env: {
        ...process.env,
        TERM: "xterm-256color"
    }
});

    shell.onData((data) => {
        if (ws.readyState === WebSocket.OPEN) {
            ws.send(data);
        }
    });

    ws.on("message", (msg) => {
        shell.write(msg.toString());
    });

    ws.on("close", () => {
        shell.kill();
    });

    shell.onExit(() => {
        ws.close();
    });
});

server.listen(3000, () => {
    console.log("http://localhost:3000");
});