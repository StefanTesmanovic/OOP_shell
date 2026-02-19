#include "InputParser.h"

#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
std::vector<std::vector<Argument>> InputParser::parse(const std::string& line) {
    std::vector<std::vector<Argument>> args;
    Argument cmd("", false), arg("", false), ostream("", false), opt("", false);
    std::string currentToken;
    bool inQuotes = false;
    bool quoted = false;
    bool dash = false;
    bool istr = false, ostr = false, append = false; //redirection flags
    bool tr = false;
    args.push_back(std::vector<Argument>());
    int currCmd = 0;
    int qCnt = 0;

    for (char c :line) {
        if (tr && dash) {
            if (c== '\"') {
                inQuotes = !inQuotes;
                qCnt++;
                currentToken += c;
                if (qCnt == 4) {
                    dash = false;
                    opt.value = currentToken;
                    currentToken.clear();
                }
                continue;
            }
            if (!std::isspace(c) && !inQuotes) {
                opt.value = currentToken;
                currentToken.clear();
                dash = false;
            } else {
                currentToken += c;
                continue;
            }
        }
        if (c == '\"') {
            inQuotes = !inQuotes;
            quoted = true;
            continue;
        }

        if (!inQuotes) {
            if (std::isspace(c) || c == '|') {
                if (cmd.value == "") {
                    cmd.value = currentToken;
                    if (currentToken == "tr") tr = true;
                    currentToken.clear();
                    goto pipe;
                }
                if (istr) {
                    if (currentToken.empty()) continue;
                    std::stringstream buffer;
                    buffer << "";
                    auto rFile = std::make_shared<std::ifstream>(currentToken);
                    if (rFile)
                        buffer << rFile->rdbuf();
                    arg.value = buffer.str();
                    arg.isQuoted = true;
                    currentToken.clear();
                    istr = false;
                    goto pipe;
                }
                if (ostr) {//beline ^
                    if (currentToken.empty()) continue;
                    ostream.value = currentToken;
                    currentToken.clear();
                    ostr = false;
                    goto pipe;
                }
                if (append) {//beline ^
                    if (currentToken.empty()) continue;
                    ostream.value = currentToken;
                    ostream.isQuoted = true;
                    currentToken.clear();
                    append = false;
                    goto pipe;
                }
                if (dash) {
                    opt.value = currentToken;
                    opt.isQuoted = quoted;
                    currentToken.clear();
                    quoted = false;
                    dash = false;
                    goto pipe;
                }
                if (!currentToken.empty() && currentToken.find_first_not_of(' ') != std::string::npos) {
                    arg.value = currentToken;
                    arg.isQuoted = quoted;
                    quoted = false;
                    currentToken.clear();
                }
                pipe:
                if (c == '|') {
                    args[currCmd].push_back(cmd);
                    args[currCmd].push_back(arg);
                    args[currCmd].push_back(opt);
                    args[currCmd].push_back(ostream);

                    cmd = Argument("", false);
                    arg = Argument("", false);
                    ostream = Argument("", false);
                    opt = Argument("", false);

                    currentToken.clear();

                    inQuotes = false;
                    quoted = false;
                    dash = false;
                    istr = false;
                    ostr = false;
                    append = false;
                    tr = false;

                    currCmd++;
                    qCnt = 0;

                    args.push_back(std::vector<Argument>());
                }
                continue;
            }
            if (c == '-') {
                dash = true;
                continue;
            }
            if (c == '>') {
                if (ostr) {
                    ostr = false;
                    append = true;
                    continue;
                }
                ostr = true;
                continue;
            }
            if (c == '<') {
                istr = true;
                continue;
            }
        }
        currentToken += c;
    }
    args[currCmd].push_back(cmd);
    args[currCmd].push_back(arg);
    args[currCmd].push_back(opt);
    args[currCmd].push_back(ostream);

    return args;
}