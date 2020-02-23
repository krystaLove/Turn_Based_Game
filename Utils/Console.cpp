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
    system("cls");
#endif
}

void Console::waitForPress() {
    std::string str;
    std::cout << "Enter to continue..\n";
    std::cin.get();
    std::getline(std::cin, str);
}

void Console::newLine() {
    std::cout << std::endl;
}
