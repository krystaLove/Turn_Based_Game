#ifndef TURN_BASED_GAME_MELEESTRIKE_H
#define TURN_BASED_GAME_MELEESTRIKE_H


#include "../Hero.h"

class MeleeStrike
        : public Strike
{
public:
    MeleeStrike(int damage, const std::shared_ptr<Position> &pos, Strike::StrikeType strikeType, int targets);
    virtual ~MeleeStrike() = default;

    virtual std::vector<std::shared_ptr<Hero> > getAvailableHeroesForStrike(std::vector<std::vector<int> > matrix, std::vector<std::shared_ptr<Hero> > heroes);
    virtual bool isAvailableForStrike(const std::shared_ptr<Hero> & hero);
    virtual int operator() (std::vector< std::shared_ptr<Hero> > & heroes);
};


#endif //TURN_BASED_GAME_MELEESTRIKE_H
