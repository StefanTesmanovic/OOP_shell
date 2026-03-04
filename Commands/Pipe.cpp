#include "Pipe.h"
#include "../Processing/CommandFactory.h"
#include<sstream>
#include "../Processing/CustomExceptions.h"

void Pipe::execute() {
    auto pipeIn = std::make_shared<std::stringstream>();
    std::string isVal = "";
    auto pipeOut = std::make_shared<std::stringstream>();

    for (int i = 0; i < allArgs.size(); i++) {
        std::unique_ptr<Command> cmd = CommandFactory::createCommand(std::vector<std::vector<Argument>>{allArgs[i]}, *outputStream);
        if (i > 0) {
            if (!cmd->streamIscin())
                throw InvalidPipeSyntax();
            cmd->setIstream(pipeIn, isVal);
        }
        if (i < allArgs.size() -1) {
            if (!cmd->getOsVal().empty())
                throw InvalidPipeSyntax();
            cmd->setOstream(pipeOut);
        }
        cmd->execute();
        isVal = cmd->getOsVal();
        pipeIn->str(pipeOut->str());
        pipeOut->str("");
        pipeOut->clear();
    }
}
