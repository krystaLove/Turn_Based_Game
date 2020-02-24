#ifndef TURN_BASED_GAME_ARCHER_H
#define TURN_BASED_GAME_ARCHER_H


#include "../Hero.h"

class Archer final
        : public  Hero
{
public:
    Archer();
    std::string getClassName() const final;
};


#endif //TURN_BASED_GAME_ARCHER_H
