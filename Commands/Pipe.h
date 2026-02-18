#ifndef UNTITLED_PIPE_H
#define UNTITLED_PIPE_H

#include "Command.h"
#include "../Processing/InputParser.h"

class Pipe : public Command {
public:
    using Command::Command;
    bool needsIstream() override;

protected:
    void execute() override;
};

inline bool Pipe::needsIstream() {
    return false;
}


#endif //UNTITLED_PIPE_H