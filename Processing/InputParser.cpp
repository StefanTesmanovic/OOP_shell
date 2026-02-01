#include "InputParser.h"
#include <iostream>

std::vector<Argument> InputParser::parse(const std::string& line) {
    std::vector<Argument> args;
    std::string currentToken;
    bool inQuotes = false;
    bool quotesFound = false; // Da li je trenutni token imao navodnike

    for (char c : line) {
        if (c == '\"') {
            inQuotes = !inQuotes;
            quotesFound = true; // Detektovali smo navodnike
            continue;
        }

        if (std::isspace(c) && !inQuotes) {
            if (!currentToken.empty() || quotesFound) {
                args.push_back({currentToken, quotesFound});
                currentToken.clear();
                quotesFound = false;
            }
        } else {
            currentToken += c;
        }
    }

    if (!currentToken.empty() || quotesFound) {
        args.push_back({currentToken, quotesFound});
    }

    return args;
}