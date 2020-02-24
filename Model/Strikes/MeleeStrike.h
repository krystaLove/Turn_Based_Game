#ifndef TURN_BASED_GAME_MELEESTRIKE_H
#define TURN_BASED_GAME_MELEESTRIKE_H


#include "Strike.h"

class MeleeStrike
        : public Strike
{
public:
    MeleeStrike(int damage, const std::shared_ptr<Position> &pos, Strike::StrikeType strikeType, int targets);

    std::vector<std::shared_ptr<Hero> > getAvailableHeroesForStrike(BattleField::StatusMatrix,
            std::vector<std::shared_ptr<Hero> >&) final;

    int operator() (std::vector< std::shared_ptr<Hero> > & heroes) final;
};


#endif //TURN_BASED_GAME_MELEESTRIKE_H
