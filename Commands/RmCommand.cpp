#include "RmCommand.h"
#include <filesystem>

namespace fs = std::filesystem;

//std::remove(filename.c_str()) == 0 -> true ako uspe, false ako ne, #include <cstdio>
void RmCommand::execute() {
    std::string filename = istreamVal;
    if (!fs::remove(filename))
        throw std::runtime_error("File not found");
}
