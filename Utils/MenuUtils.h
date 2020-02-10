#ifndef TURN_BASED_GAME_MENUUTILS_H
#define TURN_BASED_GAME_MENUUTILS_H

#include "Console.h"

struct MenuUtils {
    static bool getConfirmation();
    static int getInput(int min_option, int max_option);
};


#endif //TURN_BASED_GAME_MENUUTILS_H
