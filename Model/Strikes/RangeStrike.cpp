#include <iostream>
#include "RangeStrike.h"

RangeStrike::RangeStrike(int damage, const std::shared_ptr<Position> &pos, Strike::StrikeType strikeType, int targets)
        : Strike(damage, pos, strikeType, targets) {
    m_CombatType = CombatType::Range;
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
