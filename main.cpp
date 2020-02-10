#include "Console.h"

int main() {
    Console::writeLine("Hello!");
    Console::waitForPress();
    Console::clearScreen();
    Console::writeLine("Hi!");
    return 0;
}