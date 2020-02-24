#include <iostream>
#include "MeleeStrike.h"

MeleeStrike::MeleeStrike(int damage, const std::shared_ptr<Position> &pos, Strike::StrikeType strikeType, int targets)
        : Strike(damage, pos, strikeType, targets)
{
    m_CombatType = CombatType::MELEE;
}

std::vector<std::shared_ptr<Hero> > MeleeStrike::getAvailableHeroesForStrike(BattleField::StatusMatrix matrix,
                                                                            std::vector<std::shared_ptr<Hero> >& heroes)
{
    std::vector<std::shared_ptr<Hero> > availableForStrike;
    std::vector< std::vector<bool> > availablePosToStrike (matrix.size(), std::vector<bool>(matrix[0].size(), false));

    auto [cur_x, cur_y] = m_Pos->getPosition();

    for(int dx = 0; dx < matrix[0].size(); ++dx)
    {
        availablePosToStrike[1][dx] = true;
        availablePosToStrike[2][dx] = true;
    }

    bool allFirstLineDead = true;
    for(int dx = 0; dx < matrix[0].size(); ++dx)
    {
        if(matrix[1][dx] == BattleField::Status::ALIAS || matrix[1][dx] == BattleField::Status::ENEMY)
            allFirstLineDead = false;
    }

    if(allFirstLineDead){
        for(int dx = 0; dx < matrix[0].size(); ++dx)
            availablePosToStrike[0][dx] = true;
    }

    allFirstLineDead = true;

    for(int dx = 0; dx < matrix[0].size(); ++dx)
    {
        if(matrix[2][dx] == BattleField::Status::ALIAS || matrix[2][dx] == BattleField::Status::ENEMY)
            allFirstLineDead = false;
    }
    if(allFirstLineDead){
        for(int dx = 0; dx < matrix[0].size(); ++dx)
            availablePosToStrike[3][dx] = true;
    }

    auto attackingHeroStatus = matrix[cur_y][cur_x];

    for(auto const &hero : heroes)
    {
        if(!hero->isAlive())
            continue;
        auto onAttackHeroStatus = matrix[hero->getPosition()->getY()][hero->getPosition()->getX()];
        if
        (
                ((m_StrikeType == StrikeType::ALIAS && attackingHeroStatus == onAttackHeroStatus) ||
                (m_StrikeType == StrikeType::ENEMY && attackingHeroStatus != onAttackHeroStatus)) &&
                availablePosToStrike[hero->getPosition()->getY()][hero->getPosition()->getX()]
        )
            availableForStrike.push_back(hero);
    }
    return availableForStrike;
}

int MeleeStrike::operator()(std::vector< std::shared_ptr<Hero> > & heroes)
{
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
