#include "Shell.h"
#include "InputParser.h"
#include "CommandFactory.h"
#include <iostream>
#include <cstdio>
#include <limits>
#include <sstream>
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
    char buffer[MAX_CMD_LEN + 2];

    while (running) {
        //std::cout << "napravi da radi append\n";
        std::cout << "\n" << promptString << " ";
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
        line += "\n";
        executeLine(line);
    }
}

void Shell::executeLine(const std::string& line) {
    if (line.empty()) return;

    std::vector<std::vector<Argument>> args = InputParser::parse(line);
    if (args.empty()) return;/*
    for (auto t : args) {
        int i = 0;
        for (auto a : t) {
            std::cout << i << ":" << a.value << "\n";
            i++;
        }
    }*/


    try {
        std::unique_ptr<Command> cmd = CommandFactory::createCommand(args);
        if (cmd) {
            if (cmd->streamIscin() && cmd->needsIstream()) {
                std::stringstream buffer;
                buffer << std::cin.rdbuf();
                cmd->setIstream(std::make_shared<std::stringstream>(buffer.str()), "");
            }
            cmd->execute();
        } else {
            std::cout << "Nepoznata komanda: " << args[0][0].value << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "Greska: " << e.what() << std::endl;
    }

}

void Shell::setPrompt(const std::string newPrompt) {
    promptString = newPrompt;
}

void Shell::exitShell() {
    running = false;
}