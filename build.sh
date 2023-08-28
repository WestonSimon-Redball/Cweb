#!/bin/bash
emcc ./source/index.c -o ./out/out.js -s EXPORTED_FUNCTIONS="['_main','_modifyString']" -s "EXPORTED_RUNTIME_METHODS=['stringToUTF8', 'UTF8ToString']" -FETCH=1
