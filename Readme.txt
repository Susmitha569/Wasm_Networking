 emcc websocket_client.cpp -o websocket_client.html -lwebsocket.js
`python3 -m http.server 8000 - local server and access html
node  websocket_server.js - run the server

make HTTP Request
emcc http_client.cpp -o http_client.js -s FETCH=1 -s EXPORTED_FUNCTIONS="['_makeHTTPRequest']" -s EXPORTED_RUNTIME_METHODS="['ccall', 'cwrap']"
1.Run Json server 
json-server --watch db.json --port 8000 --host api.example.com or json-server --watch db.json

2.Run the python server - python3 -m http.server

