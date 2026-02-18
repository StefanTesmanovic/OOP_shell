#include "TouchCommand.h"
#include <fstream>
#include <sstream>

void TouchCommand::execute() {
    if (streamIscin()) {
        printError("Potrebno je ime za kreiranje fajla");
        return;
    }
    std:: string filename = istreamVal;
    if (inputStream && !streamIscin()) {
        std::stringstream buffer ;
        buffer << inputStream->rdbuf();
        if (!buffer.str().empty())
            filename = buffer.str();
    }

    std::ifstream check(filename);
    if (check.good()) {
        check.close();
        printError("Zadati fajl vec postoji: " + filename);
        return;
    }
    check.close();

    std::ofstream file(filename);
    if (!file) {
        printError("Neuspesno kreiranje fajla: " + filename);
    }
    file.close();
}