#ifndef DATECOMMAND_H
#define DATECOMMAND_H
#include "Command.h"
#include "NoArgumentCommand.h"
class DateCommand : public NoArgumentCommand {
public:
    using NoArgumentCommand::NoArgumentCommand;
    void execute() override;
    bool needsIstream() override;
};

inline bool DateCommand::needsIstream() {
    return false;
}
#endif
