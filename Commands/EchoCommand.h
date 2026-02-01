#ifndef ECHOCOMMAND_H
#define ECHOCOMMAND_H

#include "Command.h"

class EchoCommand : public Command {
public:
    void execute(const std::vector<Argument> &args) override;
};

#endif