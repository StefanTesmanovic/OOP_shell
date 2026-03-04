#include "BatchCommand.h"
#include <sstream>
#include "../Processing/Shell.h"
#include "../Processing/CustomExceptions.h"
void BatchCommand::execute() {
    if (inputStream) {
        if (inputStream->peek() == EOF) return;
        std::string buffer;
        while (std::getline(*inputStream, buffer)) {
            Shell::getInstance().executeLine(buffer + "\n", *outputStream);
        }
    } else {
        throw FileMissing(istreamVal);
    }
}