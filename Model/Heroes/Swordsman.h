#ifndef TURN_BASED_GAME_SWORDSMAN_H
#define TURN_BASED_GAME_SWORDSMAN_H


#include "../Hero.h"

class Swordsman
        : public Hero
{
public:
    Swordsman();
    virtual std::string getClassName() const;
};


#endif //TURN_BASED_GAME_SWORDSMAN_H
