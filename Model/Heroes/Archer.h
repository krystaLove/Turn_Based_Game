#ifndef TURN_BASED_GAME_ARCHER_H
#define TURN_BASED_GAME_ARCHER_H


#include "../Hero.h"

class Archer
        : public Hero
{
public:
    Archer();
    virtual std::string getClassName() const;
};


#endif //TURN_BASED_GAME_ARCHER_H
