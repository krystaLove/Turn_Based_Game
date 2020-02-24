#include <iostream>
#include "MeleeStrike.h"

MeleeStrike::MeleeStrike(int damage, const std::shared_ptr<Position> &pos, Strike::StrikeType strikeType, int targets)
        : Strike(damage, pos, strikeType, targets) {
    m_CombatType = CombatType::Melee;
}

std::vector<std::shared_ptr<Hero> > MeleeStrike::getAvailableHeroesForStrike(BattleField::StatusMatrix matrix,
                                                                            std::vector<std::shared_ptr<Hero> > heroes)
{
    std::vector<std::shared_ptr<Hero> > availableForStrike;

    auto [cur_x, cur_y] = m_Pos->getPosition();
    auto attackingHeroStatus = matrix[cur_y][cur_x];

    for(auto const &hero : heroes)
    {
        if(!hero->isAlive())
            continue;
        auto onAttackHeroStatus = matrix[hero->getPosition()->getY()][hero->getPosition()->getX()];
        if
                (
                (m_StrikeType == StrikeType::Alias && attackingHeroStatus == onAttackHeroStatus) ||
                (m_StrikeType == StrikeType::Enemy && attackingHeroStatus != onAttackHeroStatus)
                )
        {
            availableForStrike.push_back(hero);
        }
    }
    return availableForStrike;
}

int MeleeStrike::operator()(std::vector< std::shared_ptr<Hero> > & heroes) {
    std::cout << "Melee damage!" << std::endl;

    int exp = 0;
    for(auto &hero : heroes)
    {
        int prev_hp = hero->getHealth();
        hero->takeDamage(m_Damage);
        
        std::cout << "Hero slain " << hero->getClassName() << " for " << prev_hp - hero->getHealth();
        std::cout << "(" << hero->getHealth() << ")" << "HP!\n";

        if(!hero->isAlive())
            exp += hero->getExperienceForKill();
    }
    return exp;
}
