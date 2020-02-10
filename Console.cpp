#include "Console.h"

void Console::writeLine(std::string str) {
    write(str);
    std::cout << std::endl;
}

void Console::write(std::string str) {
    std::cout << str;
}

void Console::clearScreen() {
#ifdef __linux__
    system("clear");
#elif _WIN32
    system("CLS");
#endif
}

void Console::waitForPress() {
    writeLine("Press any key to continue..");
    std::cin.get();
}

void Console::newLine() {
    std::cout << std::endl;
}
