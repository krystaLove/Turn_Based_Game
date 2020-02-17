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
    Console::writeLine("Are you sure?\n");
    Console::writeLine("[1]. Yes");
    Console::writeLine("[2]. No");
    return !(getInput(1, 2) - 1);
}

std::string MenuUtils::getString() {
    std::string s;
    std::cin >> s;
    while(s.size() >= MAX_STRING_INPUT_LENGTH || s.size() < MIN_STRING_INPUT_LENGTH)
    {
        Console::writeLine("Incorrect length of string!");
        std::cin >> s;
    }
    return s;
}

int MenuUtils::getPlayerPick(const std::string &firstName, const std::string &secondName) {
    std::cout << "[1]. " << firstName << std::endl;
    std::cout << "[2]. " << secondName << std::endl << std::endl;
    std::cout << "[3]. Back" << std::endl;
    int player_pick = MenuUtils::getInput(1, 3);
    return player_pick;
}
