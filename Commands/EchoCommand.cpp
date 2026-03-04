#include "EchoCommand.h"
#include <iostream>
#include <sstream>
#include <regex>
#include "../Processing/CustomExceptions.h"
void EchoCommand::execute() {
    if (inputStream) {
        if (inputStream->peek() == EOF) return;
        std::stringstream buffer;
        buffer << inputStream->rdbuf();
        std::string s = buffer.str();
        s = std::regex_replace(s, std::regex("\\n+$"), "");
        *outputStream << s;// + "\n";
        ostreamVal = buffer.str()+"\n";// + ((!buffer.str().empty())?"\n":"");
        if (outputStream.get() == &std::cout) {
            *outputStream << "\n";
            ostreamVal += "\n";
        }
    } else {
        throw FileMissing(istreamVal);
    }

    if (istreamVal.empty()) {
        std::cout << "";
    }

    //std::cout << std::endl;
}