#include "RmCommand.h"
#include <filesystem>

namespace fs = std::filesystem;

//std::remove(filename.c_str()) == 0 -> true ako uspe, false ako ne, #include <cstdio>
void RmCommand::execute() {
    std::string filename = istreamVal;
    try {
        if (!fs::remove(filename))
            *outputStream << "Fajl nije pronadjen";
    } catch (const fs::filesystem_error& e) {
        std::cerr << "Greska pri brisanju fajla: " << e.what();
    }
}
