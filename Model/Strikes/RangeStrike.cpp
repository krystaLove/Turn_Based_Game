#include <iostream>
#include "RangeStrike.h"
#include "../../Controller/BattleField.h"

RangeStrike::RangeStrike(int damage, const std::shared_ptr<Position> &pos, Strike::StrikeType strikeType, int targets)
        : Strike(damage, pos, strikeType, targets) {
    m_CombatType = CombatType::Range;
}

bool RangeStrike::isAvailableForStrike(const std::shared_ptr<Hero> &hero) {
    return abs(m_Pos->getX() - hero->getPosition()->getX()) + abs(m_Pos->getY() - hero->getPosition()->getY()) > 1;
}

int RangeStrike::operator()(std::vector< std::shared_ptr<Hero> > & heroes) {
    std::cout << "Range Strike!" << std::endl;
    int exp = 0;
    for(auto &hero : heroes)
    {
        int prev_hp = hero->getHealth();
        hero->takeDamage(m_Damage);

        std::cout << "Hero shot " << hero->getClassName() << " for " << prev_hp - hero->getHealth();
        std::cout << "(" << hero->getHealth() << ")" << "HP!\n";

        if(!hero->isAlive())
        exp += hero->getExperienceForKill();

    }
    return exp;
}

std::vector<std::shared_ptr<Hero> > RangeStrike::getAvailableHeroesForStrike(std::vector<std::vector<int> > matrix, std::vector<std::shared_ptr<Hero> > heroes)
{
    std::vector<std::shared_ptr<Hero> > availableForStrike;

    int cur_x = m_Pos->getX();
    int cur_y = m_Pos->getY();

    for(auto const &hero : heroes)
    {
        if(matrix[hero->getPosition()->getY()][hero->getPosition()->getX()] == BattleField::Status::DEAD) continue;
        if(m_StrikeType == StrikeType::Alias)
        {
            if(matrix[cur_y][cur_x] == matrix[hero->getPosition()->getY()][hero->getPosition()->getX()])
                availableForStrike.push_back(hero);
        }
        else
        {
            if(matrix[cur_y][cur_x] != matrix[hero->getPosition()->getY()][hero->getPosition()->getX()])
                availableForStrike.push_back(hero);
        }
    }
    return availableForStrike;
}

