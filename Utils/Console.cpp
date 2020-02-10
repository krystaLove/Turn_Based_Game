#include "Console.h"

void Console::writeLine(std::string s) {
    write(s);
    std::cout << std::endl;
}

void Console::write(std::string s) {
    std::cout << s;
}

void Console::clearScreen() {
#ifdef __linux__
    system("clear");
#elif _WIN32
    system("CLS");
#endif
}

void Console::waitForPress() {
    std::string smth;
    std::cout << "Enter to continue..\n";
    std::cin.get();
    std::getline(std::cin, smth);
}

void Console::newLine() {
    std::cout << std::endl;
}
