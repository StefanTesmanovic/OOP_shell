#ifndef WC_COMMAND_H
#define WC_COMMAND_H

#include "Command.h"
#include <string>

class WcCommand : public Command {
public:
    using Command::Command;
    void execute() override;
    bool needsIstream() override;
private:
    int processText(const std::string& text);
};

inline bool WcCommand::needsIstream() {
    return true;
}
#endif