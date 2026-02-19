#ifndef UNTITLED_TRUNCATECOMMAND_H
#define UNTITLED_TRUNCATECOMMAND_H

#include "Command.h"
class TruncateCommand : public Command{
public:
    using Command::Command;
    void execute() override;
    bool needsIstream() override;
};
inline bool TruncateCommand::needsIstream() {
    return false;
}


#endif //UNTITLED_TRUNCATECOMMAND_H