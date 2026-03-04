#ifndef UNTITLED_HEADCOMMAND_H
#define UNTITLED_HEADCOMMAND_H
#include "Command.h"

class HeadCommand : public Command{
    public:
    using Command::Command;
    bool needsIstream() override;

protected:
    void execute() override;
};

inline bool HeadCommand::needsIstream() {
    return true;
}


#endif //UNTITLED_HEADCOMMAND_H