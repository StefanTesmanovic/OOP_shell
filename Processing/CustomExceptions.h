#ifndef CUSTOM_EXCEPTIONS_H
#define CUSTOM_EXCEPTIONS_H

#include <stdexcept>
#include <string>

class RedirectionException : public std::runtime_error {
public:
    RedirectionException()
        : std::runtime_error("Bad redirection use\n") {}
};

class InvalidCommandSyntax : public std::runtime_error {
public:
    InvalidCommandSyntax()
        : std::runtime_error("Invalid command syntax, order of arguments incorrect\n") {}
};
class OptionMissing : public std::runtime_error {
public:
    OptionMissing()
        : std::runtime_error("Option is required for this command\n") {}
};

class FileMissing : public std::runtime_error {
    public:
    FileMissing(std::string fileName)
        :std::runtime_error("File: " + fileName + " was not found\n"){};
};

class InvalidPipeSyntax : public std::runtime_error {
public:
    InvalidPipeSyntax():
        std::runtime_error("Error invalid pipe syntax\n"){}
};

class TooManyArguments : public std::runtime_error {
public:
    TooManyArguments()
        :std::runtime_error("Too many arguments passed to the function \n"){}
};
#endif