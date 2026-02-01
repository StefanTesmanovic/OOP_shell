#include "DateCommand.h"
#include <iostream>
#include <ctime>

void DateCommand::execute(const std::vector<Argument>& args) {
    std::time_t now = std::time(nullptr);
    char buf[100];
    std::strftime(buf, sizeof(buf), "%d.%m.%Y.", std::localtime(&now));
    std::cout << buf << std::endl;
}