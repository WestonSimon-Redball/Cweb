/*

 Author: Weston Simon
 Email: weston@wcloud.com

 Creation Date: 2023-08-26 13:18:10

 © wcloud

*/

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct htmlElement {
    char* elementName;
    struct htmlElement* elementChildren;
};

char* getElementName(const char* htmlString, int startingPos){
    char* elementName = (char *)malloc(sizeof(char) * 10);;


    for(int pos = startingPos; pos < strlen(htmlString) + 1; pos++){

        if(htmlString[pos] == ' ' || htmlString[pos] == '>'){
            return elementName;
        }else{
            int strLen = strlen(elementName);
            elementName = (char*)realloc(elementName, sizeof(char) * (strLen + 2));
            elementName[strLen] = htmlString[pos];
            elementName[strLen + 1] = '\0';

        }
        
    }

    return elementName;
}


struct htmlElement* parseHtml(const char* htmlString){

    struct htmlElement* elements = NULL;
    size_t numElements = 0;




    for(int pos; pos < strlen(htmlString) + 1; pos++){
        
        char currentCharacter = htmlString[pos];

        if(currentCharacter == '<' && htmlString[pos + 1] != '/'){
        
            struct htmlElement tempElement;
            tempElement.elementName = getElementName(htmlString, pos + 1);
            tempElement.elementChildren = NULL;
            
            numElements++;
            elements = realloc(elements, numElements * sizeof(struct htmlElement));
            elements[numElements - 1] = tempElement;
            
            

        }
    }
    return elements;
}
