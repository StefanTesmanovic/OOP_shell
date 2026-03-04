#include "Shell.h"
#include "InputParser.h"
#include "CommandFactory.h"
#include <iostream>
#include <cstdio>
#include <limits>
#include <sstream>
#include <regex>
#include <filesystem>
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
        //std::cout << "sredi da se \n\n\n lupa u funkciji ne ovde";
        std::cout << promptString << " ";

        std::cout.flush();
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
        //std::cout << "\n";
    }
}

void Shell::executeLine(const std::string& line, std::ostream& os) {
    if (line.empty()) return;
    std::string s = line;
    s = std::regex_replace(s, std::regex("\\n+$"), "");
    s+="\n";
    try {
    std::vector<std::vector<Argument>> args = InputParser::parse(s);
    if (args.empty()) return;
    /*
    std::cout << "\n";
    for (auto t : args) {
        int i = 0;
        for (auto a : t) {
            std::cout<< i << ":" << a.value << "\n";
            i++;
        }
    }*/


        std::unique_ptr<Command> cmd = CommandFactory::createCommand(args, os);
        if (cmd) {
            if (cmd->streamIscin() && cmd->needsIstream()) {
                std::stringstream buffer;
                buffer << std::cin.rdbuf();
                std::cin.clear();
                std::cout.flush();
                clearerr(stdin);
                cmd->setIstream(std::make_shared<std::stringstream>(buffer.str()), "");
            }
            cmd->execute();
        }
    }catch (const std::filesystem::filesystem_error& e ) {
        std::cout << "Error" << e.what() << "\n";
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << "\n";
    }

}

void Shell::setPrompt(const std::string newPrompt) {
    promptString = newPrompt;
}

void Shell::exitShell() {
    running = false;
}