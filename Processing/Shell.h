#ifndef SHELL_H
#define SHELL_H

#include <string>

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
    void executeLine(const std::string& line);
    void setPrompt(const std::string& newPrompt);
    void exitShell();
};

#endif