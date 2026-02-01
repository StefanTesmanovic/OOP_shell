#include "EchoCommand.h"
#include <iostream>
void EchoCommand::execute(const std::vector<Argument>& args) {
    //slucaj kad se ukuca enter odmah posle echo
    if (args.empty()) {
        std::string buffer = "";
        char c;
        while (std::cin.get(c)) {
            buffer += c;
        }

        std::cout << buffer;

        return;
    }

    auto stream = getInputStream(args[0]);

    if (stream) {
        std::cout << stream->rdbuf();
    } else {
        printError("Fajl nije pronadjen: " + args[0].value);
    }

    if (args.empty()) {
        std::cout << " ";
    }

    std::cout << std::endl;
}