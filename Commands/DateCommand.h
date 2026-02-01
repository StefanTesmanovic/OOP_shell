#ifndef DATECOMMAND_H
#define DATECOMMAND_H
#include "Command.h"
class DateCommand : public Command {
public:
    void execute(const std::vector<Argument> &args) override;
};
#endif