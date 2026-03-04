#ifndef UNTITLED_NOARGUMENTCOMMAND_H
#define UNTITLED_NOARGUMENTCOMMAND_H

#include "Command.h"
#include "../Processing/CustomExceptions.h"
#include <string>

class NoArgumentCommand : public Command {
public:
    NoArgumentCommand(std::vector<std::vector<Argument>>& args, std::ostream& oStream = std::cout)
        : Command(args, oStream) {
        if (!istreamVal.empty() || !opt.empty()) {
            throw TooManyArguments();
        }
    }

    virtual void execute() = 0;
    virtual bool needsIstream() = 0;
};

inline bool NoArgumentCommand::needsIstream() {
    return false;
}

#endif //UNTITLED_NOARGUMENTCOMMAND_H