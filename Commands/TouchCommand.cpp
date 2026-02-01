#include "TouchCommand.h"
#include <fstream>

void TouchCommand::execute(const std::vector<Argument>& args) {
    if (args.empty()) {
        printError("Potrebno je ime za kreiranje fajla");
        return;
    }

    std::string filename = args[0].value;

    std::ifstream check(filename);
    if (check.good()) {
        check.close();
        printError("Zadati fajl vec postoji: " + filename);
        return;
    }
    check.close();

    // 2. Kreiraj fajl
    std::ofstream file(filename);
    if (!file) {
        printError("Neuspesno kreiranje fajla: " + filename);
    }
    file.close();
}