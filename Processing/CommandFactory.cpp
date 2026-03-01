#include "CommandFactory.h"
#include "../Commands/EchoCommand.h"
#include "../Commands/Pipe.h"
#include "../Commands/TimeCommand.h"
#include "../Commands/DateCommand.h"
#include "../Commands/HeadCommand.h"
#include "../Commands/PromptCommand.h"
#include "../Commands/TouchCommand.h"
#include "../Commands/WcCommand.h"
#include "../Commands/PromptCommand.h"
#include "../Commands/RmCommand.h"
#include "../Commands/TruncateCommand.h"
#include "../Commands/TrCommand.h"
#include "../Commands/HeadCommand.h"


std::unique_ptr<Command> CommandFactory::createCommand(std::vector<std::vector<Argument>> argsIn) {
    if (argsIn.empty()) {
        return nullptr;
    }
    if (argsIn.size() > 1) {
        return std::unique_ptr<Pipe>(new Pipe(argsIn));
    }
    auto args = argsIn[0];
    std::string cmdName = args[0].value;
    if (cmdName == "echo")
        return std::unique_ptr<EchoCommand>(new EchoCommand(argsIn));
    if (cmdName == "time")
        return std::unique_ptr<TimeCommand>(new TimeCommand(argsIn));
    if (cmdName == "date")
        return std::unique_ptr<DateCommand>(new DateCommand(argsIn));
    if (cmdName == "touch")
        return std::unique_ptr<TouchCommand>(new TouchCommand(argsIn));
    if (cmdName == "wc")
        return std::unique_ptr<WcCommand> (new WcCommand(argsIn));
    if (cmdName == "prompt")
        return std::unique_ptr<PromptCommand> (new PromptCommand(argsIn));
    if (cmdName == "rm")
        return std::unique_ptr<RmCommand> (new RmCommand(argsIn));
    if (cmdName == "truncate")
        return std::unique_ptr<TruncateCommand> (new TruncateCommand(argsIn));
    if (cmdName == "tr")
        return std::unique_ptr<TrCommand> (new TrCommand(argsIn));
    if (cmdName == "head")
        return std::unique_ptr<HeadCommand> (new HeadCommand(argsIn));

    return nullptr;
}
