#ifndef TOUCHCOMMAND_H
#define TOUCHCOMMAND_H
#include "Command.h"
class TouchCommand : public Command {
public:
    void execute(const std::vector<Argument> &args) override;
};
#endif