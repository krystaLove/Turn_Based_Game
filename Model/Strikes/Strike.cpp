#include "Strike.h"

Strike::Strike(int damage, const std::shared_ptr<Position> & pos, StrikeType strikeType, int targets) {
    m_Damage = damage;
    m_Pos = pos;
    m_Targets = targets;
    m_StrikeType = strikeType;
}

Strike::CombatType Strike::getCombatType() {
    return m_CombatType;
}

int Strike::getTargets() {
    return m_Targets;
}
std::vector<std::shared_ptr<Hero> > Strike::getAvailableHeroesForStrike(BattleField::StatusMatrix matrix,
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

