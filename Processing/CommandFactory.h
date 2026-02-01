#ifndef COMMANDFACTORY_H
#define COMMANDFACTORY_H

#include <memory>
#include <string>
#include "../Commands/Command.h"

class CommandFactory {
public:
    static std::unique_ptr<Command> createCommand(const std::string& commandName);
};

#endif