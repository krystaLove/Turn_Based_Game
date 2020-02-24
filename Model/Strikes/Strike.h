#ifndef TURN_BASED_GAME_STRIKE_H
#define TURN_BASED_GAME_STRIKE_H

#include <vector>
#include "../Hero.h"
#include "../../Menu/Battle/BattleField.h"

class Strike {
public:
    enum class CombatType {MELEE, RANGE, HEAL};
    enum class StrikeType {ALIAS, ENEMY};

    Strike(int damage, const std::shared_ptr<Position> & pos, StrikeType strikeType, int targets);
    virtual ~Strike() = default;

    CombatType getCombatType();
    int getTargets();

    virtual std::vector<std::shared_ptr<Hero> > getAvailableHeroesForStrike(BattleField::StatusMatrix matrix,
                                                                            std::vector<std::shared_ptr<Hero> >&);
    virtual int operator() (std::vector< std::shared_ptr<Hero> > & heroes) = 0;

protected:
    int m_Damage;
    int m_Targets;
    std::shared_ptr<Position> m_Pos;

    CombatType m_CombatType;
    StrikeType m_StrikeType;
};


#endif //TURN_BASED_GAME_STRIKE_H
