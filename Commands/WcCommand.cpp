#include "WcCommand.h"
#include <iostream>
#include <string>
#include <vector>

void WcCommand::execute(const std::vector<Argument>& args) {
    std::string option;
    Argument sourceArg;
    bool hasSrc = false;

    if (!args.empty()) {
        if (!args[0].isQuoted && args[0].value[0] == '-') {
            option = args[0].value;
            if (args.size() > 1) {
                sourceArg = args[1];
                hasSrc = true;
            }
        } else { // ako nema opcije ispisuje se i broj reci i broj karaktera
            sourceArg = args[0];
            hasSrc = true;
        }
    }

    std::string textToProcess;

    if (hasSrc) {
        auto stream = getInputStream(sourceArg);
        if (stream) {
            char c;
            while (stream->get(c)) {
                textToProcess += c;
            }
        } else {
            printError("Nemoguce je otvoriti fajl: " + sourceArg.value);
            return;
        }
    } else {
        char c;
        while (std::cin.get(c)) {
            textToProcess += c;
        }
    }

    processText(textToProcess, option);
}

void WcCommand::processText(const std::string& text, const std::string& option) {
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

    if (option == "-w") {
        std::cout << words << std::endl;
    } else if (option == "-c") {
        std::cout << chars << std::endl;
    } else {
        std::cout << words << " " << chars << std::endl;
    }
}