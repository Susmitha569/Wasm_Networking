const WebSocket = require('ws');

const server = new WebSocket.Server({ port: 8080 });

server.on('connection', ws => {
    ws.on('message', message => {
        console.log('received: %s', message);
    });
    ws.send('Hello, WebSocket client Hai from WebSocket server!');
});

console.log('WebSocket server is running on ws://localhost:8080');
