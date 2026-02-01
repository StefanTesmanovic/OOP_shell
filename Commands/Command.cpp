#include "Command.h"
#include <fstream>
#include <sstream>

void Command::printError(const std::string& message) const {
    std::cerr << "Greska: " << message << std::endl;
}

std::unique_ptr<std::istream> Command::getInputStream(const Argument& arg) {
    if (arg.isQuoted) {
        return std::make_unique<std::stringstream>(arg.value);
    }

    auto fileStream = std::make_unique<std::ifstream>(arg.value);

    if (!fileStream->is_open()) {
        return nullptr;
    }

    return fileStream;
}