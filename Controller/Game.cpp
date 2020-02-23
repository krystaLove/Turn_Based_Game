#include "Game.h"
#include "../Utils/Console.h"
#include "../Utils/MenuUtils.h"
#include "TeamManager.h"
#include "BattleController.h"


Game::Game() {
    m_Players.push_back(std::make_unique<Player>());
    m_Players.push_back(std::make_unique<Player>());
    m_Run = true;
}

void Game::run() {
    Console::clearScreen();
    Console::writeLine("Welcome to the Game!");

    Console::writeLine("Write first Player's name: ");
    m_Players[0]->setName(MenuUtils::getString());

    Console::writeLine("Write second Player's name: ");
    m_Players[1]->setName(MenuUtils::getString());

    Console::clearScreen();

    while(m_Run)
    {
        update();
    }
}

void Game::update() {

    Console::writeLine("= Old Game 0.001alpha =\n");
    Console::writeLine("[1]. Start");
    Console::writeLine("[2]. Manage Heroes\n");
    Console::writeLine("[3]. Exit");

    int option = MenuUtils::getInput(static_cast<int>(MENU_OPTION::START), static_cast<int>(MENU_OPTION::EXIT));

    switch (static_cast<MENU_OPTION>(option)){
        case MENU_OPTION::EXIT:
        {
            m_Run = false;
            return;
        }
        case MENU_OPTION::MANAGE:
        {
            TeamManager teamManager(m_Players);
            teamManager.run();
            break;
        }
        case MENU_OPTION::START:
        {
            if(m_Players[0]->isPlayerReady() && m_Players[1]->isPlayerReady()){
                BattleController battleController(m_Players);
                battleController.run();
            }
            Console::waitForPress();
            break;
        }
    }

    Console::clearScreen();
}
