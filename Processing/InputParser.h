#ifndef INPUTPARSER_H
#define INPUTPARSER_H

#include <vector>
#include <string>

//Argument komande, cuva informaciju o tome da li je fajl ili direktan argument pod navodnicima
struct Argument {
    std::string value;
    bool isQuoted;
};

class InputParser {
public:
    static std::vector<std::vector<Argument>> parse(const std::string& line);
};

#endif