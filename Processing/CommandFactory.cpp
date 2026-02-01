#include "CommandFactory.h"

#include "../Commands/EchoCommand.h"
#include "../Commands/TimeCommand.h"
#include "../Commands/DateCommand.h"
#include "../Commands/TouchCommand.h"
#include "../Commands/WcCommand.h"


std::unique_ptr<Command> CommandFactory::createCommand(const std::string& commandName) {
    if (commandName == "echo") {
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
    }
    return nullptr;
}