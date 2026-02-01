#ifndef WC_COMMAND_H
#define WC_COMMAND_H

#include "Command.h"
#include <string>

class WcCommand : public Command {
public:
    void execute(const std::vector<Argument>& args) override;

private:
    void processText(const std::string& text, const std::string& option);
};

#endif