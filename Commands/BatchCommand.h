#ifndef UNTITLED_BATCHCOMMAND_H
#define UNTITLED_BATCHCOMMAND_H

#include "Command.h"

class BatchCommand : public Command{
public:
    using Command::Command;
    void execute() override;
    bool needsIstream() override;
};
inline bool BatchCommand::needsIstream() {
    return true;
}

#endif //UNTITLED_BATCHCOMMAND_H