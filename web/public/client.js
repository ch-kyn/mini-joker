const term = new Terminal({
    cols: 200,
    rows: 120,
    cursorBlink: true,
    fontSize: 16
});

term.open(document.getElementById("terminal"));

const ws = new WebSocket("ws://" + location.host);

term.onData(data => ws.send(data));

ws.onmessage = e => term.write(e.data);
