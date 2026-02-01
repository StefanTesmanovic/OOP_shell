#include "TimeCommand.h"
#include <iostream>
#include <ctime>

void TimeCommand::execute(const std::vector<Argument>& args) {
    std::time_t now = std::time(nullptr);
    char buf[100];
    std::strftime(buf, sizeof(buf), "%H:%M:%S", std::localtime(&now));
    std::cout << buf << std::endl;
}