
// Wait for the Emscripten module to be ready
Module.onRuntimeInitialized = function () {
    console.log("hi")
    document.getElementById('modifyButton').addEventListener('click', function () {
        // Input string
        var inputStr = document.getElementById("tb").value;

        // Convert the input string to a null-terminated C string
        //var inputStrPtr = Module._malloc(inputStr.length + 1);
        var inputStrPtr = (inputStr.length + 1)
        Module.stringToUTF8(inputStr, inputStrPtr, inputStr.length + 1);

        // Call the C function with the input string
        var resultPtr = Module._modifyString(inputStrPtr);

        // Convert the result pointer to a JavaScript string
        var resultStr = Module.UTF8ToString(resultPtr);

        // Free the memory used for the input string and result string
        //Module._free(inputStrPtr);
        //Module._free(resultPtr);

        console.log(resultStr);
    });


};

function something(elementType, innerText){
        const newP = document.createElement(elementType);
        const newContent = document.createTextNode(innerText)

        newP.appendChild(newContent)

        document.body.appendChild(newP)
    }