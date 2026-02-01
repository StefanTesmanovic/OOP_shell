#ifndef INPUTPARSER_H
#define INPUTPARSER_H

#include <vector>
#include <string>

//Argument komande, cuva informaciju o tome da li je fajl ili direktan argument pod navodnicima
struct Argument {
    std::string value;
    bool isQuoted;
};
//Napravljeno je da se svuda argumenti cuvaju kao lista za slucaj da u nekim komandama moze da ima vise argumenata i opcije su isto argumenti u implementaciji

class InputParser {
public:
    static std::vector<Argument> parse(const std::string& line);
};

#endif