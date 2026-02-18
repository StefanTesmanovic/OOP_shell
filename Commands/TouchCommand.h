#ifndef TOUCHCOMMAND_H
#define TOUCHCOMMAND_H
#include "Command.h"
class TouchCommand : public Command {
public:
    using Command::Command;
    void execute() override;
    bool needsIstream() override;
};

inline bool TouchCommand::needsIstream() {
    return false;
}
#endif
