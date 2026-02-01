#ifndef TIMECOMMAND_H
#define TIMECOMMAND_H
#include "Command.h"
class TimeCommand : public Command {
public:
    void execute(const std::vector<Argument> &args) override;
};
#endif