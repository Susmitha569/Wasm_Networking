#include <emscripten.h>
#include <stdio.h>

extern "C" {
    EMSCRIPTEN_KEEPALIVE
    void makeHTTPRequest() {
        printf("Making HTTP request...\n");
        // Call the JavaScript function (defined later) to perform the Fetch
        emscripten_run_script("fetchDataFromAPI()");
    }
}
