#ifndef UNTITLED_RMCOMMAND_H
#define UNTITLED_RMCOMMAND_H

#include "Command.h"

class RmCommand : public Command{
public:
    using Command::Command;
    void execute() override;
    bool needsIstream() override;
};

inline bool RmCommand::needsIstream() {
    return false;
}


#endif //UNTITLED_RMCOMMAND_H