#include <set>
#include "BattleField.h"
#include "../Utils/Console.h"
#include "../Configs/GameConfig.h"

BattleField::BattleField(const std::vector<std::shared_ptr<Hero> > &heroes_alias,
                         const std::vector<std::shared_ptr<Hero> > &heroes_enemy) {

    m_StatusField = BattleField::StatusMatrix (FIELD_H, std::vector<int> (FIELD_W, Status::EMPTY));
    m_HeroField = BattleField::StatusMatrix (FIELD_H, std::vector<int> (FIELD_W, Status::EMPTY));

    m_Heroes_Alias = heroes_alias;
    m_Heroes_Enemy = heroes_enemy;

    m_Mode = Mode::STATUS;
}

void BattleField::_refreshField() {

    //Refresh Status
    for(auto &row : m_StatusField)
        for(auto &x : row)
            x = Status::EMPTY;

    for(auto &row : m_HeroField)
        for(auto &x : row)
            x = Status::EMPTY;

    for(auto &hero : m_Heroes_Alias) {
        int hero_x = hero->getPosition()->getX();
        int hero_y = hero->getPosition()->getY();

        if(hero_y >= m_StatusField.size() || hero_y < 0 || hero_x >= m_StatusField[hero_y].size() || hero_x < 0)
            continue;

        m_StatusField[hero_y][hero_x] = hero->isAlive() ? Status::ALIAS : Status::DEAD;
        m_HeroField[hero_y][hero_x] = hero->getClass();
    }
    for(auto &hero : m_Heroes_Enemy) {
        int hero_x = hero->getPosition()->getX();
        int hero_y = hero->getPosition()->getY();

        if(hero_y >= m_StatusField.size() || hero_y < 0 || hero_x >= m_StatusField[hero_y].size() || hero_x < 0)
            continue;

        m_StatusField[hero_y][hero_x] = hero->isAlive() ? Status::ENEMY : Status::DEAD;
        m_HeroField[hero_y][hero_x] = hero->getClass();
    }

}

const BattleField::StatusMatrix& BattleField::getStatusMatrix() const{
    return m_StatusField;
}

void BattleField::drawField() {
    _refreshField();
    Console::writeLine("[ Battle Field ]");
    if(m_Mode == Mode::STATUS)
        _drawStatusField();
    else
        _drawHeroField();

}
void BattleField::_drawStatusField() {
    for (auto &row: m_StatusField) {
        std::cout << " ";
        for (auto &x : row) {
            char mark = 0;
            switch (x) {
                case Status::EMPTY: {
                    mark = '.';
                    break;
                }
                case Status::DEAD: {
                    mark = 'D';
                    break;
                }
                case Status::ALIAS: {
                    mark = 'A';
                    break;
                }
                case Status::ENEMY: {
                    mark = 'E';
                    break;
                }
            }
            std::cout << mark;
        }
        std::cout << "\n";
    }
}

void BattleField::_drawHeroField() {
    for(int row = 0; row < m_HeroField.size(); ++row)
    {
        std::cout << " ";
        for(int x = 0; x < m_HeroField[row].size(); ++x)
        {
            if(m_StatusField[row][x] == Status::EMPTY)
            {
                std::cout << ".";
                continue;
            }
            std::cout << getCharForHero(m_HeroField[row][x]);
        }
        std::cout << std::endl;
    }
}

char BattleField::getCharForHero(int heroClass) {
    switch(heroClass)
    {
        case Hero::HeroClass::SWORDSMAN:
            return 'S';
        case Hero::HeroClass::APPRENTICE:
            return 'A';
        case Hero::HeroClass::PEASANT:
            return 'P';
        case Hero::HeroClass::ARCHER:
            return 'R';
    }
}

void BattleField::changeMode() {
    if (m_Mode == Mode::STATUS)
        m_Mode = Mode::HEROES;
    else
        m_Mode = Mode::STATUS;
}

void BattleField::showLegend() {
    Console::writeLine("[ Battle Field ]");
    _drawHeroField();
    Console::newLine();
    Console::writeLine("[ Legend of Battle field ]");

    std::set<int> usingHeroes;
    for(int row = 0; row < m_HeroField.size(); ++row)
    {
        for(int x = 0; x < m_HeroField[row].size(); ++x)
        {
            if(m_StatusField[row][x] == Status::EMPTY) continue;
            usingHeroes.insert(m_HeroField[row][x]);
        }
    }
    for(auto type : usingHeroes)
    {
        std::cout << getCharForHero(type) << " - " << Hero::getClassName(static_cast<Hero::HeroClass>(type)) << "\n";
    }
}
