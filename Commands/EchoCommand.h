#ifndef ECHOCOMMAND_H
#define ECHOCOMMAND_H

#include "Command.h"

class EchoCommand : public Command {
public:
    using Command::Command;
    void execute() override;
    bool needsIstream() override;
};
inline bool EchoCommand::needsIstream() {
    return true;
}
#endif