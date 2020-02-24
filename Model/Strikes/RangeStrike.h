#ifndef TURN_BASED_GAME_RANGESTRIKE_H
#define TURN_BASED_GAME_RANGESTRIKE_H


#include "Strike.h"

class RangeStrike
        : public Strike
{
public:
    RangeStrike(int damage, const std::shared_ptr<Position> & pos, StrikeType strikeType, int targets);

    int operator() (std::vector< std::shared_ptr<Hero> > & heroes) final;
};


#endif //TURN_BASED_GAME_RANGESTRIKE_H
