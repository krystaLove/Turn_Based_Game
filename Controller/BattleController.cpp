#include "BattleController.h"
#include "../Utils/Console.h"
#include "../Utils/MenuUtils.h"
#include "../HeroLogic/LevelUp.h"

#include <algorithm>
#include <set>

BattleController::BattleController(std::vector<std::shared_ptr<Player> > &players) {
    m_Players = players;
    m_Run = false;
    m_Turn = 0;
    m_CurrentPlayer = 0;

    m_BattleField = std::make_shared<BattleField>(
            BattleField(players[0]->getPlayerTeam(), players[1]->getPlayerTeam()));

    _initOrder();
    _initPositions();
    _refreshHeroes();
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
    END_TYPE isEnd = _checkForEnd();
    if(isEnd != END_TYPE::CONTINUE)
    {
        if(isEnd == END_TYPE::ONE_WIN)
            _endBattle(m_Players[0]);
        else
            _endBattle(m_Players[1]);

        m_Run = false;
        _refreshHeroes();
        return;
    }
    std::pair<std::shared_ptr<Hero>, int> & currentHeroAndPlayer = _getCurrentTurnHero();
    std::shared_ptr<Hero>& currentHero = currentHeroAndPlayer.first;

    _showBattleInfo();
    Console::writeLine("[ Current Hero ]");
    std::cout << m_Players[currentHeroAndPlayer.second]->getName() << "'s turn\n";

    Console::write("Hero: ");
    currentHero->showShortInfo();
    currentHero->setDefend(false);
    std::cout << "Position: " << *currentHero->getPosition() << "\n\n";
    _showMenu();

    int pick = MenuUtils::getInput(MENU_OPTION::ATTACK, MENU_OPTION::EXIT);
    switch (pick)
    {
        case MENU_OPTION::ATTACK:
        {
            Console::clearScreen();
            if(!_attackOption(currentHero)) break;
            m_Turn++;
            break;
        }
        case MENU_OPTION::DEFEND:
        {
            Console::clearScreen();
            if(!MenuUtils::getConfirmation()) break;
            currentHero->setDefend(true);
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
    Console::writeLine("[ Current order ] \n");
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
    while(!m_HeroOrder[m_Turn % m_HeroOrder.size()].first->isAlive())
    {
        m_HeroOrder.erase(m_HeroOrder.begin() + m_Turn % m_HeroOrder.size());
    }
    return m_HeroOrder[m_Turn % m_HeroOrder.size()];
}

bool BattleController::_attackOption(std::shared_ptr<Hero> & curHero) {
    const std::shared_ptr<Strike> & strike = curHero->getStrike();

    std::vector<std::shared_ptr<Hero> > available;
    std::vector<std::pair< std::shared_ptr<Hero>, int > > toStrike;

    std::set<int> chosen;

    available.reserve(m_Players[0]->getPlayerTeam().size() + m_Players[1]->getPlayerTeam().size());

    auto firstPlayerTeam = strike->getAvailableHeroesForStrike
            (m_BattleField->getStatusMatrix(), m_Players[0]->getPlayerTeam());
    auto secondPlayerTeam = strike->getAvailableHeroesForStrike
            (m_BattleField->getStatusMatrix(), m_Players[1]->getPlayerTeam());

    available.insert(available.end(), firstPlayerTeam.begin(), firstPlayerTeam.end());
    available.insert(available.end(), secondPlayerTeam.begin(), secondPlayerTeam.end());

    bool apply = false;

    if(available.empty())
    {
        Console::writeLine("There is no heroes current hero can strike!");
        Console::waitForPress();
        return false;
    }

    while(!apply)
    {
        Console::writeLine("[ Current Hero ]\n");
        curHero->showShortInfo();
        Console::newLine();
        Console::writeLine("[ Available heroes to strike ]\n");

        int max_option = 0;

        if(!firstPlayerTeam.empty())
        {
            std::cout << m_Players[0]->getName() << "'s heroes: \n";
            for(auto &hero : firstPlayerTeam)
            {
                printf("[%d]. ", ++max_option);
                hero->showShortInfo();
            }
            Console::newLine();
        }
        if(!secondPlayerTeam.empty())
        {
            std::cout << m_Players[1]->getName() << "'s heroes: \n";
            for(auto &hero : secondPlayerTeam)
            {
                printf("[%d]. ", ++max_option);
                hero->showShortInfo();
            }
            Console::newLine();
        }
        if(!toStrike.empty())
            Console::writeLine("[ Your choice ]\n");
        for(int i = 0; i < toStrike.size(); ++i)
        {
            printf("[%d]: ", i + 1);
            toStrike[i].first->showShortInfo();
        }

        Console::newLine();
        _attackMenu();

        int pick = MenuUtils::getInput(ATTACK_OPTION::APPLY, ATTACK_OPTION::BACK);

        switch(pick)
        {
            case ATTACK_OPTION::APPLY:
            {
                if(chosen.empty())
                {
                    Console::writeLine("You have chosen no heroes to strike!");
                    Console::waitForPress();
                    break;
                }
                std::vector<std::shared_ptr<Hero> > toStrikeApply;
                for(auto &pair : toStrike)
                    toStrikeApply.push_back(pair.first);

                Console::clearScreen();
                int gainedExperience = strike->operator()(toStrikeApply);
                if(gainedExperience > 0)
                    std::cout << "Hero gained " << gainedExperience << "EXP!\n";
                curHero->addExperience(gainedExperience);
                Console::waitForPress();
                return true;
            }
            case ATTACK_OPTION::BACK:
            {
                return false;
            }
            case ATTACK_OPTION::ADD:
            {
                if(toStrike.size() >= strike->getTargets())
                {
                    std::cout << "This hero can attack only " << strike->getTargets() << " targets!\n";
                    Console::waitForPress();
                    break;
                }
                Console::writeLine("Choose hero to add");
                int hero_pick = MenuUtils::getInput(1, available.size());
                if(chosen.find(hero_pick) != chosen.end())
                {
                    Console::writeLine("You have already chosen this hero!");
                    Console::waitForPress();
                    break;
                }
                chosen.insert(hero_pick);
                toStrike.push_back({available[hero_pick - 1], hero_pick});
                break;
            }
            case ATTACK_OPTION::REMOVE:
            {
                Console::clearScreen();
                if(toStrike.empty())
                {
                    Console::writeLine("You have chosen no heroes!");
                    Console::waitForPress();
                    break;
                }

                Console::writeLine("Choose what hero you want to remove from your Strike list\n");

                for(int i = 0; i < toStrike.size(); ++i)
                {
                    printf("[%d]: ", i + 1);
                    toStrike[i].first->showShortInfo();
                }

                printf("\n[%d]. Back ", toStrike.size() + 1);

                int hero_pick = MenuUtils::getInput(1, toStrike.size() + 1);
                if(hero_pick == toStrike.size() + 1) break;

                chosen.erase(toStrike[hero_pick].second);
                toStrike.erase(toStrike.begin() + hero_pick - 1);

                break;
            }

        }
        Console::clearScreen();

    }

}

void BattleController::_attackMenu() {
    Console::writeLine("[1]. Apply");
    Console::writeLine("[2]. Add");
    Console::writeLine("[3]. Remove\n");
    Console::writeLine("[4]. Back");
}

BattleController::END_TYPE BattleController::_checkForEnd() {
    bool firstDead = true, secondDead = true;
    for(auto &hero : m_Players[0]->getPlayerTeam())
    {
        if(hero->isAlive())
        {
            firstDead = false;
            break;
        }
    }
    for(auto &hero : m_Players[1]->getPlayerTeam())
    {
        if(hero->isAlive())
        {
            secondDead = false;
            break;
        }
    }
    if(firstDead) return END_TYPE::SECOND_WIN;
    if(secondDead) return END_TYPE::ONE_WIN;
    return END_TYPE::CONTINUE;
}

void BattleController::_endBattle(std::shared_ptr<Player> &player) {
    Console::writeLine("[ Congratulations! ]\n");
    std::cout << player->getName() <<" won the battle at " << m_Turn << " turn" << std::endl;

    Console::waitForPress();
    Console::clearScreen();

    LevelUp levelUp;

    for(int hero_id = 0; hero_id < player->getPlayerTeam().size(); ++hero_id)
    {
        Console::clearScreen();

        auto hero = player->getPlayerTeam().at(hero_id);
        if(!hero->canLevelUp()) continue;

        Console::writeLine("[ Your hero can level up! ]");
        hero->showShortInfo();

        std::vector<int> ways = levelUp.getWaysToLevelUp(hero->getClass());
        if(ways.empty())
        {
            Console::writeLine("There is no ways to transform this hero");
            Console::waitForPress();
            continue;
        }

        Console::writeLine("[ Transform ]");
        for(int i = 0; i < ways.size(); ++i)
        {
            std::cout << "[" << i + 1 << "]. ";
            switch (ways[i])
            {
                case Hero::HeroClass::APPRENTICE:
                {
                    std::cout << "Apprentice";
                    break;
                }
                case Hero::HeroClass::ARCHER:
                {
                    std::cout << "Archer";
                    break;
                }
                case Hero::HeroClass::SWORDSMAN:
                {
                    std::cout << "Swordsman";
                    break;
                }
                case Hero::HeroClass::PEASANT:
                {
                    std::cout << "Peasant";
                    break;
                }
            }
            std::cout << "\n";
        }
        std::cout << "[" << ways.size() + 1 << "]. No transform\n";

        int pick = MenuUtils::getInput(1, ways.size() + 1);
        if(pick == ways.size() + 1) continue;

        auto tranformedHero = HeroGenerator::generateHero(ways[pick - 1]);
        player->setHeroById(tranformedHero, hero_id);
    }
    m_Run = false;
}

void BattleController::_refreshHeroes() {
    for(auto &hero : m_Players[0]->getPlayerTeam())
    {
        hero->refreshHero();
    }
    for(auto &hero : m_Players[1]->getPlayerTeam())
    {
        hero->refreshHero();
    }
}
