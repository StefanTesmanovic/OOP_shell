#include "Shell.h"
#include "InputParser.h"
#include "CommandFactory.h"
#include <iostream>
#include <cstdio>
#include <limits>
Shell* Shell::instance = nullptr;

Shell::Shell() : running(true), promptString("$") {}

Shell& Shell::getInstance() {
    if (instance == nullptr) {
        instance = new Shell();
    }
    return *instance;
}

void Shell::run() {
    const int MAX_CMD_LEN = 512;
    char buffer[MAX_CMD_LEN + 1];

    while (running) {
        std::cout << promptString << " ";
        std::cout.flush();

        //ciscenje cin-a od flagova zbog funkcija wc i echo
        std::cin.clear();
        clearerr(stdin);

        std::cin.getline(buffer, MAX_CMD_LEN + 1);

        if (std::cin.eof() && std::cin.gcount() == 0) {
            break;
        }

        if (std::cin.fail()) {
            std::cin.clear();

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        std::string line(buffer);

        executeLine(line);
    }
}

void Shell::executeLine(const std::string& line) {
    if (line.empty()) return;

    std::vector<Argument> tokens = InputParser::parse(line);
    if (tokens.empty()) return;

    std::string cmdName = tokens[0].value;
    std::vector<Argument> args;

    if (tokens.size() > 1) {
        args.assign(tokens.begin() + 1, tokens.end());
    }

    try {
        std::unique_ptr<Command> cmd = CommandFactory::createCommand(cmdName);
        if (cmd) {
            cmd->execute(args);
        } else {
            std::cout << "Nepoznata komanda: " << cmdName << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "Greska: " << e.what() << std::endl;
    }

}

void Shell::setPrompt(const std::string& newPrompt) {
    promptString = newPrompt;
}

void Shell::exitShell() {
    running = false;
}