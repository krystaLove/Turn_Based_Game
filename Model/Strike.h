#ifndef TURN_BASED_GAME_STRIKE_H
#define TURN_BASED_GAME_STRIKE_H


#include <vector>
#include "Hero.h"
#include "../Controller/BattleField.h"

class Strike {
public:
    enum class CombatType {Melee, Range, Heal};
    enum class StrikeType {Alias, Enemy};

    Strike(int damage, const std::shared_ptr<Position> & pos, StrikeType strikeType, int targets);
    virtual ~Strike() = default;

    CombatType getCombatType();
    int getTargets();

    virtual std::vector<std::shared_ptr<Hero> > getAvailableHeroesForStrike(BattleField::StatusMatrix matrix,
                                                                            std::vector<std::shared_ptr<Hero> >) = 0;
    virtual bool isAvailableForStrike(const std::shared_ptr<Hero> & hero) = 0;
    virtual int operator() (std::vector< std::shared_ptr<Hero> > & heroes) = 0;

protected:
    int m_Damage;
    std::shared_ptr<Position> m_Pos;
    CombatType m_CombatType;
    StrikeType m_StrikeType;
    int m_Targets;
};


#endif //TURN_BASED_GAME_STRIKE_H
