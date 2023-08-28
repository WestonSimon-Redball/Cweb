#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <emscripten.h>



EMSCRIPTEN_KEEPALIVE
void addItemToDOM(const char* elementType, const char* text) {
    char functionToCall[] = "something('%s', '%s')";

    size_t scriptSize = strlen(text) + strlen(elementType) + strlen(functionToCall) + 1;

    char* script = (char*)malloc(scriptSize);
    snprintf(script, scriptSize, functionToCall, elementType, text);

    printf("%s \n", script);

    emscripten_run_script(script);

    free(script);
}

