#include "TeamManager.h"
#include "../../Utils/Console.h"
#include "../../Utils/MenuUtils.h"
#include "../../Configs/GameConfig.h"
#include "../../HeroLogic/HeroGenerator.h"


TeamManager::TeamManager(std::vector<std::shared_ptr<Player> > &players) {
    m_Players = players;
    m_Run = true;
}

void TeamManager::run() {
    Console::clearScreen();
    while(m_Run)
    {
        update();
    }
}


void TeamManager::_showMenu() {
    Console::writeLine("= Team Managing =\n");
    Console::writeLine("[1]. Construct team from trash");
    Console::writeLine("[2]. Show Team");
    Console::writeLine("[3]. Add Hero");
    Console::writeLine("[4]. Remove Hero\n");
    Console::writeLine("[5]. Back");
}

void TeamManager::update() {
    _showMenu();

    int option = MenuUtils::getInput(static_cast<int>(MENU_TYPE::CONSTRUCT), static_cast<int>(MENU_TYPE::EXIT));
    switch(static_cast<MENU_TYPE>(option))
    {
        case MENU_TYPE::CONSTRUCT:
        {
            Console::clearScreen();
            Console::writeLine("Choosing this option your team will be discarded!");
            if(!MenuUtils::getConfirmation()) break;
            Console::clearScreen();
            Console::writeLine("Choose player!\n");
            int pick = MenuUtils::getPlayerPick(m_Players[0]->getName(), m_Players[1]->getName());
            if(pick < 3)
            {
                _constructTeam(pick - 1);
            }
            break;
        }
        case MENU_TYPE::EXIT:
        {
            m_Run = false;
            Console::clearScreen();
            return;
        }
        case MENU_TYPE::SHOW:
        {
            Console::clearScreen();
            m_Players[0]->showShortInfo();
            m_Players[1]->showShortInfo();
            break;
        }
        case MENU_TYPE::ADD:
        {
            Console::clearScreen();
            Console::writeLine("For whom do you want to add hero?\n");
            int pick = MenuUtils::getPlayerPick(m_Players[0]->getName(), m_Players[1]->getName());
            if(pick < 3)
                _addRandomHero(pick - 1);
            break;
        }
        case MENU_TYPE::REMOVE:
        {
            Console::clearScreen();
            Console::writeLine("From what team do you want to remove hero?\n");
            int pick = MenuUtils::getPlayerPick(m_Players[0]->getName(), m_Players[1]->getName());
            if(pick < 3)
            {
                _removeHero(pick - 1);
            }
            break;
        }
    }
    Console::waitForPress();
    Console::clearScreen();
}

//Manager options

void TeamManager::_addRandomHero(int player_id) {
    std::shared_ptr<Player> &player = m_Players[player_id];

    if(player->getTeamSize() >= MAX_HEROES_PER_PLAYER)
    {
        Console::writeLine("There is no more space in this team!");
        return;
    }

    player->addHero(HeroGenerator::generateRandomHero());
}

void TeamManager::_removeHero(int player_id) {
    Console::clearScreen();

    std::shared_ptr<Player> & player = m_Players[player_id];
    if(!player->isHavingHeroes())
    {
        Console::writeLine("This player has no heroes to remove!");
        return;
    }
    Console::clearScreen();
    player->showShortInfo();
    Console::writeLine("What hero do you want to remove from your team?");

    player->removeHero(MenuUtils::getInput(0, player->getTeamSize()));
    Console::writeLine("Hero was removed from the team!");
}

void TeamManager::_constructTeam(int player_id) {
    Console::clearScreen();
    Console::writeLine("Choose: \n");
    Console::writeLine("[1]. Random Team");
    Console::writeLine("[2]. Your own\n");
    Console::writeLine("[3]. Back");

    std::shared_ptr<Player> &player = m_Players[player_id];

    int pick = MenuUtils::getInput(1, 3);
    Console::clearScreen();
    switch (pick)
    {
        case 1:
        {
            player->removeTeam();

            player->setTeam(HeroGenerator::generateRandomTeam());
            player->showShortInfo();

            break;
        }
        case 2:
        {
            player->removeTeam();

            Console::writeLine("[ Four Base Hero Classes ] \n");

            std::cout << "[" << static_cast<int>(Hero::Class::PEASANT) << "]. Peasant\n";
            std::cout << "[" << static_cast<int>(Hero::Class::APPRENTICE) << "]. Apprentice\n";
            std::cout << "[" << static_cast<int>(Hero::Class::ARCHER) << "]. Archer\n";
            std::cout << "[" << static_cast<int>(Hero::Class::SWORDSMAN) << "]. Swordsman\n";

            for(int i = 0; i < MAX_HEROES_PER_PLAYER; ++i)
            {
                int classPick = MenuUtils::getInput(static_cast<int>(Hero::Class::PEASANT),
                                                    static_cast<int>(Hero::Class::SWORDSMAN));
                player->addHero(HeroGenerator::generateHero(static_cast<Hero::Class>(classPick)));
            }

            player->showShortInfo();

            break;
        }
        case 3:
        {
            return;
        }
    }
}

