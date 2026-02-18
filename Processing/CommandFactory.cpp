#include "CommandFactory.h"
#include <algorithm>

#include "../Commands/EchoCommand.h"
#include "../Commands/Pipe.h"
#include "../Commands/TimeCommand.h"
#include "../Commands/DateCommand.h"
#include "../Commands/TouchCommand.h"
#include "../Commands/WcCommand.h"
#include "../Commands/WcCommand.h"


std::unique_ptr<Command> CommandFactory::createCommand(std::vector<std::vector<Argument>> argsIn) {
    if (argsIn.empty()) {
        return nullptr;
    }
    if (argsIn.size() > 1) {
        return std::unique_ptr<Pipe>(new Pipe(argsIn));
    }
    auto args = argsIn[0];
    std::string cmdName = args[0].value;
    if (cmdName == "echo") {
        return std::unique_ptr<EchoCommand>(new EchoCommand(argsIn));
    }else if (cmdName == "time") {
        return std::unique_ptr<TimeCommand>(new TimeCommand(argsIn));
    } else if (cmdName == "date") {
        return std::unique_ptr<DateCommand>(new DateCommand(argsIn));
    } else if (cmdName == "touch") {
        return std::unique_ptr<TouchCommand>(new TouchCommand(argsIn));
    } else if (cmdName == "wc") {
        return std::unique_ptr<WcCommand> (new WcCommand(argsIn));
    }
    /*if (commandName == "echo") {
        return std::unique_ptr<EchoCommand>(new EchoCommand());
    }
    else if (commandName == "time") {
        return std::unique_ptr<TimeCommand>(new TimeCommand());
    }
    else if (commandName == "date") {
        return std::unique_ptr<DateCommand>(new DateCommand());
    }
    else if (commandName == "touch") {
        return std::unique_ptr<TouchCommand>(new TouchCommand());
    }
    else if (commandName == "wc") {
        return std::unique_ptr<WcCommand>(new WcCommand());
    }*/
    return nullptr;
}