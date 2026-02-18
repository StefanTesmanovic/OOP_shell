#include "DateCommand.h"
#include <iostream>
#include <ctime>

void DateCommand::execute() {
    std::time_t now = std::time(nullptr);
    char buf[100];
    std::strftime(buf, sizeof(buf), "%d.%m.%Y.", std::localtime(&now));
    *outputStream << buf;
}