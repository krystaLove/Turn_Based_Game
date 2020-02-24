#ifndef TURN_BASED_GAME_HEALSTRIKE_H
#define TURN_BASED_GAME_HEALSTRIKE_H


#include "Strike.h"

class HealStrike
        : public Strike
{
public:
    HealStrike(int damage, const std::shared_ptr<Position> &pos, Strike::StrikeType strikeType, int targets);

    int operator() (std::vector< std::shared_ptr<Hero> > & heroes) final;

};


#endif //TURN_BASED_GAME_HEALSTRIKE_H
