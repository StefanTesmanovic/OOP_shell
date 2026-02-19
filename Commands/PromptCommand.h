#ifndef UNTITLED_PROMPTCOMMAND_H
#define UNTITLED_PROMPTCOMMAND_H
#include "Command.h"


class PromptCommand : public Command{
public:
    using Command::Command;
    void execute() override;
    bool needsIstream() override;
};

inline bool PromptCommand::needsIstream() {
    return false;
}
#endif //UNTITLED_PROMPTCOMMAND_H