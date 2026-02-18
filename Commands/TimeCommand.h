#ifndef TIMECOMMAND_H
#define TIMECOMMAND_H
#include "Command.h"
class TimeCommand : public Command {
public:
    using Command::Command;
    void execute() override;
    bool needsIstream() override;
};
inline bool TimeCommand::needsIstream() {
    return false;
}
#endif