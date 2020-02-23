#ifndef TURN_BASED_GAME_RANGESTRIKE_H
#define TURN_BASED_GAME_RANGESTRIKE_H


#include "../Strike.h"

class RangeStrike
        : public Strike
{
public:
    RangeStrike(int damage, const std::shared_ptr<Position> & pos, StrikeType strikeType, int targets);
    virtual ~RangeStrike() = default;

    std::vector<std::shared_ptr<Hero> > getAvailableHeroesForStrike(BattleField::StatusMatrix,
            std::vector<std::shared_ptr<Hero> >) final;
    int operator() (std::vector< std::shared_ptr<Hero> > & heroes) final;
    bool isAvailableForStrike(const std::shared_ptr<Hero> & hero) final;
};


#endif //TURN_BASED_GAME_RANGESTRIKE_H
