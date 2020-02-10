#ifndef TURN_BASED_GAME_MELEESTRIKE_H
#define TURN_BASED_GAME_MELEESTRIKE_H


#include "../Hero.h"

class MeleeStrike
        : public Strike
{
public:
    MeleeStrike(int damage, const std::shared_ptr<Position>& pos);
    virtual ~MeleeStrike() = default;
    virtual bool isAvailableForStrike(const std::shared_ptr<Hero> & hero);
    virtual void operator() (std::vector<Hero*> & heroes);
};


#endif //TURN_BASED_GAME_MELEESTRIKE_H
