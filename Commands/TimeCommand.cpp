#include "TimeCommand.h"
#include <iostream>
#include <ctime>

void TimeCommand::execute() {
    std::time_t now = std::time(nullptr);
    char buf[100];
    std::strftime(buf, sizeof(buf), "%H:%M:%S", std::localtime(&now));
    std::string timeString(buf);
    *outputStream << timeString;
}