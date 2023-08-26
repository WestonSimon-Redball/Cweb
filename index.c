
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <emscripten.h>
#include "helpers.h"
#include "parsers.h"

int main(){
    struct htmlElement* elements = parseHtml("<div> <p> hi </p> </div>");
    printf("sizeof elements %lu \n", sizeof(elements));
    for(int element = 0; element < sizeof(elements) + 1; element++){
        if(elements[element].elementName != NULL){
            printf("element name %s \n", elements[element].elementName);
    
        }
    }
    return 0;
}

const char* modifyString(char* input) {
    printf("%s \n", input);

    addItemToDOM("li" ,input);
    return input;
}


