#include "PromptCommand.h"
#include "../Processing/Shell.h"
#include <sstream>

void PromptCommand::execute() {
    Shell& shell = Shell::getInstance();
    if (streamIscin() || (inputStream == nullptr && istreamVal.empty())) {
        shell.setPrompt("");
        return;
    }
    shell.setPrompt(istreamVal);
}
