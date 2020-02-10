#include "HealStrike.h"

HealStrike::HealStrike(int damage, const std::shared_ptr<Position> &pos) : Strike(damage, pos) {

}

void HealStrike::operator()(std::vector<Hero *> &heroes) {
    for(auto hero : heroes)
    {
        int prev_hp = hero->getHealth();
        hero->takeDamage(m_Damage);
        std::cout << "Hero healed " << hero->getClassName() << " for " << hero->getHealth() - prev_hp;
        std::cout << "(" << hero->getHealth() << ")" << "HP!\n";
    }
}

bool HealStrike::isAvailableForStrike(const std::shared_ptr<Hero> &hero) {
    return true;
}
