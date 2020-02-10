#ifndef TURN_BASED_GAME_HEALSTRIKE_H
#define TURN_BASED_GAME_HEALSTRIKE_H


#include "../Hero.h"

class HealStrike
        : public Strike
{
public:
    HealStrike(int damage, const std::shared_ptr<Position>& pos);
    virtual ~HealStrike() = default;

    virtual void operator() (std::vector<Hero*> & heroes);
    virtual bool isAvailableForStrike(const std::shared_ptr<Hero> & hero);
};


#endif //TURN_BASED_GAME_HEALSTRIKE_H
