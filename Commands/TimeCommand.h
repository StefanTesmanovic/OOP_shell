#ifndef TIMECOMMAND_H
#define TIMECOMMAND_H
#include "Command.h"
#include "NoArgumentCommand.h"
class TimeCommand : public NoArgumentCommand {
public:
    using NoArgumentCommand::NoArgumentCommand;
    void execute() override;
    bool needsIstream() override;
};
inline bool TimeCommand::needsIstream() {
    return false;
}
#endif