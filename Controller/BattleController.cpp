#include "BattleController.h"
#include "../Utils/Console.h"
#include "../Utils/MenuUtils.h"

#include <algorithm>

BattleController::BattleController(std::vector<std::shared_ptr<Player> > &players) {
    m_Players = players;
    m_Run = false;
    m_Turn = 0;
    m_CurrentPlayer = 0;

    m_BattleField = std::make_shared<BattleField>(
            BattleField(players[0]->getPlayerTeam(), players[1]->getPlayerTeam()));

    _initOrder();
    _initPositions();
}

void BattleController::run() {
    m_Run = true;
    while (m_Run)
    {
        update();
    }
}

void BattleController::update() {
    Console::clearScreen();
    std::pair<std::shared_ptr<Hero>, int> & currentHeroAndPlayer = _getCurrentTurnHero();
    std::shared_ptr<Hero>& currentHero = currentHeroAndPlayer.first;

    _showBattleInfo();
    Console::writeLine("[ Current Hero ]");
    std::cout << m_Players[currentHeroAndPlayer.second]->getName() << "'s turn\n";

    Console::write("Hero: ");
    currentHero->showShortInfo();
    currentHero->setDefend();
    std::cout << "Position: " << *currentHero->getPosition() << "\n\n";
    _showMenu();

    int pick = MenuUtils::getInput(MENU_OPTION::ATTACK, MENU_OPTION::EXIT);
    switch (pick)
    {
        case MENU_OPTION::ATTACK:
        {
            m_Turn++;
            break;
        }
        case MENU_OPTION::DEFEND:
        {
            Console::clearScreen();
            if(!MenuUtils::getConfirmation()) break;
            currentHero->setDefend();
            Console::clearScreen();
            std::cout << currentHero->getClassName() << " is defending!\n" << std::endl;
            m_Turn++;
            Console::waitForPress();

            break;
        }

        case MENU_OPTION::ORDER:
        {
            Console::clearScreen();
            _showOrder();
            Console::waitForPress();

            break;
        }
        case MENU_OPTION::CHANGE_MODE:
        {
            m_BattleField->changeMode();

            break;
        }
        case MENU_OPTION::LEGEND:
        {
            Console::clearScreen();
            m_BattleField->showLegend();
            Console::waitForPress();

            break;
        }
    }

    Console::clearScreen();
}

void BattleController::_showBattleInfo() {
    Console::writeLine("= Battle =");
    printf("[ Turn : %d ]\n\n", m_Turn);
    m_BattleField->drawField();
    Console::newLine();
}

void BattleController::_initOrder() {
    for(auto &hero : m_Players[0]->getPlayerTeam())
    {
        m_HeroOrder.push_back({hero, 0});
    }
    for(auto &hero : m_Players[1]->getPlayerTeam())
    {
        m_HeroOrder.push_back({hero, 1});
    }
    sort(m_HeroOrder.begin(), m_HeroOrder.end(),
            [](std::pair<std::shared_ptr<Hero>, int> a, std::pair<std::shared_ptr<Hero>, int> b)
            {
                return a.first->getInitiative() > b.first->getInitiative();
            }
    );
}

void BattleController::_showOrder() {
    Console::writeLine("Current order: ");
    if(m_HeroOrder.size() == 0) return;
    int currentHero = m_Turn % m_HeroOrder.size();
    for(int i = currentHero; i < m_HeroOrder.size(); ++i)
    {
        auto hero_player = m_HeroOrder.at(i);
        if(!hero_player.first->isAlive()) continue;
        printf("%10s - ", m_Players[hero_player.second]->getName().c_str());
        hero_player.first->showShortInfo();
    }
    for(int i = 0; i < currentHero; ++i)
    {
        auto hero_player = m_HeroOrder.at(i);
        if(!hero_player.first->isAlive()) continue;
        printf("%10s - ", m_Players[hero_player.second]->getName().c_str());
        hero_player.first->showShortInfo();
    }
}

void BattleController::_showMenu() {
    Console::writeLine("[1]. Attack");
    Console::writeLine("[2]. Defend\n");
    Console::writeLine("[3]. Show order");
    Console::writeLine("[4]. Show legend of field");
    Console::writeLine("[5]. Change mode of field");
}

void BattleController::_initPositions() {
    int cur = 0;
    for(auto &hero : m_Players[0]->getPlayerTeam())
    {
        hero->getPosition()->setPosition({cur % 2, cur / 2});
        cur++;
    }
    cur = 7;
    for(auto &hero : m_Players[1]->getPlayerTeam())
    {
        hero->getPosition()->setPosition({cur % 2, cur / 2});
        cur--;
    }
}

std::pair<std::shared_ptr<Hero>, int> & BattleController::_getCurrentTurnHero(){
    return m_HeroOrder[m_Turn % m_HeroOrder.size()];
}
