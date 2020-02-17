#ifndef TURN_BASED_GAME_HEALSTRIKE_H
#define TURN_BASED_GAME_HEALSTRIKE_H


#include "../Hero.h"

class HealStrike
        : public Strike
{
public:
    HealStrike(int damage, const std::shared_ptr<Position> &pos, Strike::StrikeType strikeType, int targets);
    virtual ~HealStrike() = default;


    virtual std::vector<std::shared_ptr<Hero> > getAvailableHeroesForStrike(std::vector<std::vector<int> > matrix, std::vector<std::shared_ptr<Hero> >);
    virtual int operator() (std::vector< std::shared_ptr<Hero> > & heroes);

    virtual bool isAvailableForStrike(const std::shared_ptr<Hero> & hero);
};


#endif //TURN_BASED_GAME_HEALSTRIKE_H
