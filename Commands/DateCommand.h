#ifndef DATECOMMAND_H
#define DATECOMMAND_H
#include "Command.h"
class DateCommand : public Command {
public:
    using Command::Command;
    void execute() override;
    bool needsIstream() override;
};

inline bool DateCommand::needsIstream() {
    return false;
}
#endif
