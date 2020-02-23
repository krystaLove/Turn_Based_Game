#include <iostream>
#include "MeleeStrike.h"
#include "../../Controller/BattleField.h"


MeleeStrike::MeleeStrike(int damage, const std::shared_ptr<Position> &pos, Strike::StrikeType strikeType, int targets)
        : Strike(damage, pos, strikeType, targets) {
    m_CombatType = CombatType::Melee;
}

std::vector<std::shared_ptr<Hero> > MeleeStrike::getAvailableHeroesForStrike(BattleField::StatusMatrix matrix,
        std::vector<std::shared_ptr<Hero> > heroes)
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

int MeleeStrike::operator()(std::vector< std::shared_ptr<Hero> > & heroes) {
    int exp = 0;
    std::cout << "Melee damage!" << std::endl;
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

bool MeleeStrike::isAvailableForStrike(const std::shared_ptr<Hero> &hero) {
    return true;
}
