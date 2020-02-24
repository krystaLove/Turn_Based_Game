#include "HealStrike.h"

HealStrike::HealStrike(int damage, const std::shared_ptr<Position> &pos, Strike::StrikeType strikeType, int targets)
        : Strike(damage, pos, strikeType, targets) {
    m_CombatType = CombatType::Heal;
}

int HealStrike::operator()(std::vector< std::shared_ptr<Hero> > & heroes) {
    int exp = 0;
    for(auto hero : heroes)
    {
        int prev_hp = hero->getHealth();
        hero->takeDamage(m_Damage);

        std::cout << "Hero healed " << hero->getClassName() << " for " << hero->getHealth() - prev_hp;
        std::cout << "(" << hero->getHealth() << ")" << "HP!\n";

        if(!hero->isAlive())
            exp += hero->getExperienceForKill();
    }
    return exp;
}

