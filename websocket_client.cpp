#include <iostream>
#include <emscripten/emscripten.h>
#include <emscripten/html5.h>
#include <emscripten/websocket.h>

EM_BOOL on_open(int eventType, const EmscriptenWebSocketOpenEvent* e, void* userData) {
    std::cout << "WebSocket connection opened" << std::endl;
    emscripten_websocket_send_utf8_text(e->socket, "Hello, WebSocket server!");
    return EM_TRUE;
}

EM_BOOL on_message(int eventType, const EmscriptenWebSocketMessageEvent* e, void* userData) {
    std::cout << "Message from server: " << e->data << std::endl;
    return EM_TRUE;
}

int main() {
    EmscriptenWebSocketCreateAttributes ws_attrs = {
        "ws://localhost:8080", // WebSocket URL
        NULL, true
    };
    EMSCRIPTEN_WEBSOCKET_T ws = emscripten_websocket_new(&ws_attrs);

    emscripten_websocket_set_onopen_callback(ws, NULL, on_open);
    emscripten_websocket_set_onmessage_callback(ws, NULL, on_message);

    emscripten_exit_with_live_runtime(); // Keep the runtime alive to keep WebSocket open
    return 0;
}
