#include "CreateTeamManager.h"
#include "../Utils/Console.h"
#include "../Utils/MenuUtils.h"
#include "../Model/Heroes/Peasant.h"
#include "../Model/Heroes/Swordsman.h"
#include "../Model/Heroes/Archer.h"
#include "../Model/Heroes/Apprentice.h"

CreateTeamManager::CreateTeamManager(std::vector<std::shared_ptr<Player> > &players) {
    m_Players = players;
    m_Run = true;
}

void CreateTeamManager::run() {
    Console::clearScreen();
    while(m_Run)
    {
        update();
    }
}


void CreateTeamManager::showMenu() {
    std::cout << "= Team Managing =\n";
    std::cout << "[1]. Show Team\n";
    std::cout << "[2]. Add Hero\n";
    std::cout << "[3]. Change Hero\n";
    std::cout << "[4]. Back\n";
}

void CreateTeamManager::update() {
    showMenu();
    int option = MenuUtils::getInput(MENU_TYPE::SHOW, MENU_TYPE::EXIT);
    switch(option)
    {
        case MENU_TYPE::EXIT:
        {
            m_Run = false;
            Console::clearScreen();
            return;
        }
        case MENU_TYPE::SHOW:
        {
            Console::clearScreen();
            Console::writeLine("[ First player's team ]");

            m_Players[0]->showShortInfo();
            Console::writeLine("\n[ Second player's team ]");
            m_Players[1]->showShortInfo();
            break;
        }
        case MENU_TYPE::ADD:
        {
            Console::clearScreen();
            Console::writeLine("For whom do you want to add hero?");
            Console::writeLine("[1] - First, [2] - Second");
            int player_pick = MenuUtils::getInput(1, 2);
            addRandomHero(player_pick - 1);
            break;
        }
    }
    Console::waitForPress();
    Console::clearScreen();
}

void CreateTeamManager::addRandomHero(int player_id) {
    int random_choice = rand() % 4;
    switch(random_choice)
    {
        case 0:
        {
            m_Players[player_id]->addHero(std::make_shared<Peasant>(Peasant()));
            break;
        }
        case 1:
        {
            m_Players[player_id]->addHero(std::make_shared<Swordsman>(Swordsman()));
            break;
        }
        case 2:
        {
            m_Players[player_id]->addHero(std::make_shared<Archer>(Archer()));
            break;
        }
        case 3:
        {
            m_Players[player_id]->addHero(std::make_shared<Apprentice>(Apprentice()));
            break;
        }
    }
}
