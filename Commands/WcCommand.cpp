#include "WcCommand.h"
#include <iostream>
#include <string>
#include <sstream>

void WcCommand::execute() {
    std::stringstream buffer;
    buffer << inputStream->rdbuf();
    std::string textToProcess = buffer.str();

    int output = processText(textToProcess);
    *outputStream << output;
}

int WcCommand::processText(const std::string& text) {
    long words = 0;
    long chars = text.length();
    bool inWord = false;

    for (char c : text) {
        if (std::isspace(c)) {
            inWord = false;
        } else if (!inWord) {
            words++;
            inWord = true;
        }
    }

    if (opt == "w") {
        return words;
    } else if (opt == "c") {
        return chars;
    }
}