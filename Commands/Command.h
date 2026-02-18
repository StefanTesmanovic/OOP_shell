#ifndef COMMAND_H
#define COMMAND_H

#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include "../Processing/InputParser.h"

class Command {
public:
    virtual ~Command() = default;
    Command(std::vector<std::vector<Argument>>& args);
    virtual void execute() = 0;
    void setIstream(std::shared_ptr<std::istream>, std::string);
    bool streamIscin(); // vraca da li je cin input stream
    void setOstream(std::shared_ptr<std::ostream>);
    virtual bool needsIstream() = 0;
    std::string getOsVal();
protected:
    void printError(const std::string& message) const;
    std::shared_ptr<std::istream> inputStream; //Ovo je zapravo argument, moze biti fajl ili string
    std::shared_ptr<std::ostream> outputStream;
    std::string opt;
    std::string ostreamVal;
    std::string istreamVal;
    std::vector<std::vector<Argument>> allArgs;
};

#endif