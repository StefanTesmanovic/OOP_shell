#include "EchoCommand.h"
#include <iostream>
#include <sstream>
void EchoCommand::execute() {
    if (inputStream) {
        if (inputStream->peek() == EOF) return;
        std::stringstream buffer;
        buffer << inputStream->rdbuf();
        *outputStream << buffer.str() + "\n";
        ostreamVal = buffer.str() + ((!buffer.str().empty())?"\n":"");
    } else {
        printError("Fajl nije pronadjen: " + istreamVal);
    }

    if (istreamVal.empty()) {
        std::cout << "";
    }

    //std::cout << std::endl;
}