#ifndef SHELL_H
#define SHELL_H

#include <string>
#include <iostream>

class Shell {
private:
    static Shell* instance;
    bool running;
    std::string promptString;

    Shell();

public:
    Shell(const Shell&) = delete;
    Shell& operator=(const Shell&) = delete;
    static Shell& getInstance();

    void run();
    void executeLine(const std::string& line, std::ostream& os = std::cout);
    void setPrompt(std::string newPrompt);
    void exitShell();
};

#endif