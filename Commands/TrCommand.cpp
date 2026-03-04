#include "TrCommand.h"
#include<sstream>
#include<regex>
void TrCommand::execute() {
    std::stringstream buffer;
    buffer << inputStream->rdbuf();
    std::string textToProcess = buffer.str();

    std::string output = processText(textToProcess);
    output = std::regex_replace(output, std::regex("\\n+$"), "");
    *outputStream << output<< "\n";
}

std::string TrCommand::processText(const std::string& text) {
    std::string retStr = text;
    std::string targetStr = "";
    std::string replaceStr = "";

    size_t firstQuote = opt.find('"');
    if (firstQuote == std::string::npos) {
        throw std::runtime_error("Nema navodnika");
    }

    size_t secondQuote = opt.find('"', firstQuote + 1);
    if (secondQuote == std::string::npos) {
        throw std::runtime_error("Fali ti navodnik");
    }
    targetStr = opt.substr(firstQuote + 1, secondQuote - firstQuote - 1);

    size_t thirdQuote = opt.find('"', secondQuote + 1);
    if (thirdQuote != std::string::npos) {
        size_t fourthQuote = opt.find('"', thirdQuote + 1);
        if (fourthQuote != std::string::npos) {
            replaceStr = opt.substr(thirdQuote + 1, fourthQuote - thirdQuote - 1);
        }
    }

    if (!targetStr.empty()) {
        size_t pos = 0;
        while ((pos = retStr.find(targetStr, pos)) != std::string::npos) {
            retStr.replace(pos, targetStr.length(), replaceStr);
            pos += replaceStr.length();
        }
    }
    return retStr;
}