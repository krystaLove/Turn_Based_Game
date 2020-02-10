#include "MenuUtils.h"

int MenuUtils::getInput(int min_option, int max_option) {
    int option = 1;
    std::cin >> option;
    while(option < min_option || option > max_option)
    {
        Console::writeLine("Incorrect option! Choose again!");
        std::cin >> option;
    }
    return option;
}

bool MenuUtils::getConfirmation() {
    Console::writeLine("Are you sure?");
    Console::writeLine("[0] - Decline, [1] - Confirm");
    return getInput(0, 1);
}
