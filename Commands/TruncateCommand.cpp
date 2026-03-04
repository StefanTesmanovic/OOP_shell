#include "TruncateCommand.h"

#include <fstream>
#include <sstream>

void TruncateCommand::execute() {
    if (!inputStream) {
        printError("Fajl nije pronadjen: " + istreamVal);
        return;
    }
    if (!istreamVal.empty()) {
        auto out = std::make_shared<std::ofstream>(istreamVal);
    }
}