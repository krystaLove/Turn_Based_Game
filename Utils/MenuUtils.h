#ifndef TURN_BASED_GAME_MENUUTILS_H
#define TURN_BASED_GAME_MENUUTILS_H

#include "Console.h"

#define MAX_STRING_INPUT_LENGTH 15
#define MIN_STRING_INPUT_LENGTH 3

struct MenuUtils {
    static bool getConfirmation();
    static int getInput(int min_option, int max_option);
    static std::string getString();
    static int getPlayerPick(const std::string& firstName, const std::string& secondName);
};


#endif //TURN_BASED_GAME_MENUUTILS_H
