#include "BatchCommand.h"
#include <sstream>
#include "../Processing/Shell.h"
void BatchCommand::execute() {
    if (inputStream) {
        if (inputStream->peek() == EOF) return;
        std::string buffer;
        while (std::getline(*inputStream, buffer)) {
            Shell::getInstance().executeLine(buffer + "\n", *outputStream);
            *outputStream << "\n";
        }
    } else {
        printError("Fajl nije pronadjen: " + istreamVal);
    }

    if (istreamVal.empty()) {
        std::cout << "";
    }

    //std::cout << std::endl;
}