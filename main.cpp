#include "Processing/Shell.h"
#include <iostream>

int main() {
    Shell& shell = Shell::getInstance();
    shell.run();
    return 0;
}
