#include "Game.h"
#include "../Utils/Console.h"
#include "../Utils/MenuUtils.h"
#include "CreateTeamManager.h"

void Game::run() {
    Console::clearScreen();
    while(m_Run)
    {
        update();
    }
}

void Game::showMainMenu() {
    Console::writeLine("= Welcome to Old Game =");
    Console::writeLine("[1]. Start");
    Console::writeLine("[2]. Manage Heroes");
    Console::writeLine("[3]. Exit");
}

void Game::update() {
    showMainMenu();
    int option = MenuUtils::getInput(MENU_OPTION::START, MENU_OPTION::EXIT);
    switch (option){
        case MENU_OPTION::EXIT:
        {
            m_Run = false;
            return;
        }
        case MENU_OPTION::MANAGE:
        {
            CreateTeamManager teamManager(m_Players);
            teamManager.run();
        }
    }
    Console::clearScreen();
}

Game::Game() {
    m_Players.push_back(std::make_unique<Player>(Player()));
    m_Players.push_back(std::make_unique<Player>(Player()));
    m_Run = true;
}
