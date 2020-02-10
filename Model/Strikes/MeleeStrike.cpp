#include <iostream>
#include "MeleeStrike.h"

MeleeStrike::MeleeStrike(int damage, const std::shared_ptr<Position>& pos) : Strike(damage, pos) {

}

void MeleeStrike::operator()(std::vector<Hero *> &heroes) {
    for(auto hero : heroes)
    {
        int prev_hp = hero->getHealth();
        hero->takeDamage(m_Damage);
        std::cout << "Hero slain " << hero->getClassName() << " for " << prev_hp - hero->getHealth();
        std::cout << "(" << hero->getHealth() << ")" << "HP!\n";
    }
}

bool MeleeStrike::isAvailableForStrike(const std::shared_ptr<Hero> &hero) {
    return true;
}
