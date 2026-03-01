#include "HeadCommand.h"
#include <sstream>
void HeadCommand::execute() {
    if (inputStream) {
        ostreamVal = "";
        if (inputStream->peek() == EOF) return;
        std::string buffer;
        int n = 0;
        try {
            n = std::stoi(opt.substr(1, opt.length()-1));
        } catch (const std::invalid_argument& e) {
            std::cerr << e.what() << '\n';
        }
        for (int i = 0; i < n; i++) {
            if (!std::getline(*inputStream, buffer))
                break;
            *outputStream << buffer << "\n";
            ostreamVal +=(buffer + "\n");
        }
    } else {
        printError("Nema ulaznih podataka: " + istreamVal);
    }

    if (istreamVal.empty()) {
        std::cout << "";
    }


}
