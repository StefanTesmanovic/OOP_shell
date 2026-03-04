#include "CommandFactory.h"

#include "../Commands/BatchCommand.h"
#include "../Commands/EchoCommand.h"
#include "../Commands/Pipe.h"
#include "../Commands/TimeCommand.h"
#include "../Commands/DateCommand.h"
#include "../Commands/HeadCommand.h"
#include "../Commands/PromptCommand.h"
#include "../Commands/TouchCommand.h"
#include "../Commands/WcCommand.h"
#include "../Commands/RmCommand.h"
#include "../Commands/TruncateCommand.h"
#include "../Commands/TrCommand.h"
#include "CustomExceptions.h"

std::unique_ptr<Command> CommandFactory::createCommand(std::vector<std::vector<Argument>> argsIn, std::ostream& oStream) {
    if (argsIn.empty()) {
        return nullptr;
    }
    if (argsIn.size() > 1) {
        return std::unique_ptr<Pipe>(new Pipe(argsIn, oStream));
    }
    auto args = argsIn[0];
    std::string cmdName = args[0].value;
    if (cmdName == "echo")
        return std::unique_ptr<EchoCommand>(new EchoCommand(argsIn, oStream));
    if (cmdName == "time")
        return std::unique_ptr<TimeCommand>(new TimeCommand(argsIn, oStream));
    if (cmdName == "date")
        return std::unique_ptr<DateCommand>(new DateCommand(argsIn, oStream));
    if (cmdName == "touch")
        return std::unique_ptr<TouchCommand>(new TouchCommand(argsIn, oStream));
    if (cmdName == "wc") {
        WcCommand *cmd =  new WcCommand(argsIn, oStream);
        if (cmd->optIsQuoted()) {
            throw InvalidCommandSyntax();
        }
        return std::unique_ptr<WcCommand>(cmd);
    }
    if (cmdName == "prompt")
        return std::unique_ptr<PromptCommand> (new PromptCommand(argsIn, oStream));
    if (cmdName == "rm")
        return std::unique_ptr<RmCommand> (new RmCommand(argsIn, oStream));
    if (cmdName == "truncate")
        return std::unique_ptr<TruncateCommand> (new TruncateCommand(argsIn, oStream));
    if (cmdName == "tr") // Ovde srediti order i neophodnost "opcije"
        return std::unique_ptr<TrCommand> (new TrCommand(argsIn, oStream));
    if (cmdName == "head"){
        HeadCommand *cmd =  new HeadCommand(argsIn, oStream);
        if (cmd->optIsQuoted()) {
            throw InvalidCommandSyntax();
        }
        return std::unique_ptr<HeadCommand>(cmd);
    }
    if (cmdName == "batch")
        return std::unique_ptr<BatchCommand> (new BatchCommand(argsIn, oStream));
    return nullptr;
}
