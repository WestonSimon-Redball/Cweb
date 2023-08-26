#!/bin/bash
emcc index.c -o out.js -s EXPORTED_FUNCTIONS="['_main','_modifyString']" -s "EXPORTED_RUNTIME_METHODS=['stringToUTF8', 'UTF8ToString']" -s EXIT_RUNTIME=1
