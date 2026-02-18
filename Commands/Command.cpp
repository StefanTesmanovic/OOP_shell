#include "Command.h"
#include <fstream>
#include <sstream>

Command::Command(std::vector<std::vector<Argument>>& argsIn) { // args = [arg, opt, ostream]
    allArgs = argsIn;
    auto args = argsIn[0];
    args.erase(args.begin());
    auto arg = args[0];
    if (arg.isQuoted) {
        inputStream =  std::make_shared<std::stringstream>(arg.value);
        istreamVal = arg.value;
    }else if (arg.value.empty()) {
        inputStream.reset(&std::cin, [](std::istream*){});
    }else {
        auto file = std::make_shared<std::ifstream>(arg.value);
        if (file->is_open()) {
            inputStream = file;
            istreamVal = arg.value;
        } else {
            inputStream = nullptr;
            istreamVal = arg.value;
        }
    }
    auto ostream = args[2];
    if (ostream.value.empty()) {
        outputStream.reset(&std::cout, [](std::ostream*){});
        ostreamVal = "";
    }else {
        ostreamVal = ostream.value;
        if (ostream.isQuoted)
            outputStream = std::make_shared<std::ofstream>(ostream.value, std::ios::app);
        else
            outputStream = std::make_shared<std::ofstream>(ostream.value);
    }
    opt = args[1].value;
}
void Command::printError(const std::string& message) const {
    std::cerr << "Greska: " << message;
}

bool Command::streamIscin() {
    return inputStream.get() == &std::cin;
}

void Command::setIstream(std::shared_ptr<std::istream> istream, std::string istreamValue) {
     inputStream = istream;
    istreamVal = istreamValue;
}
std::string Command::getOsVal() {
    return ostreamVal;
}

void Command::setOstream(std::shared_ptr<std::ostream> ostream) {
    outputStream = ostream;
}