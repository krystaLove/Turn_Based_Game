#ifndef TURN_BASED_GAME_RANGESTRIKE_H
#define TURN_BASED_GAME_RANGESTRIKE_H


#include "../Hero.h"

class RangeStrike
        : public Strike
{
public:
    RangeStrike(int damage, const std::shared_ptr<Position> & pos, StrikeType strikeType, int targets);
    virtual ~RangeStrike() = default;


    virtual std::vector<std::shared_ptr<Hero> > getAvailableHeroesForStrike(std::vector<std::vector<int> > matrix, std::vector<std::shared_ptr<Hero> >);
    virtual int operator() (std::vector< std::shared_ptr<Hero> > & heroes);
    virtual bool isAvailableForStrike(const std::shared_ptr<Hero> & hero);
};


#endif //TURN_BASED_GAME_RANGESTRIKE_H
