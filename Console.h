#ifndef TURN_BASED_GAME_CONSOLE_H
#define TURN_BASED_GAME_CONSOLE_H

#include <iostream>

struct Console {
    static void writeLine(std::string str);
    static void write(std::string str);
    static void newLine();
    static void clearScreen();
    static void waitForPress();
};


#endif //TURN_BASED_GAME_CONSOLE_H
