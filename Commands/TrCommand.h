#ifndef UNTITLED_TRCOMMAND_H
#define UNTITLED_TRCOMMAND_H

#include "Command.h"

class TrCommand : public Command {
public:
    using Command::Command;
    void execute() override;
    bool needsIstream() override;
private:
    std::string processText(const std::string& text);
};

inline bool TrCommand::needsIstream() {
    return true;
}


#endif //UNTITLED_TRCOMMAND_H