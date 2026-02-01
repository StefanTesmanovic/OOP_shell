#ifndef COMMAND_H
#define COMMAND_H

#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include "../Processing/InputParser.h"

class Command {
public:
    virtual ~Command() = default;

    virtual void execute(const std::vector<Argument>& args) = 0;

protected:
    void printError(const std::string& message) const;
    std::unique_ptr<std::istream> getInputStream(const Argument& arg);
};

#endif