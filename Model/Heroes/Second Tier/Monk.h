#ifndef TURN_BASED_GAME_MONK_H
#define TURN_BASED_GAME_MONK_H


#include "../../Hero.h"

class Monk
        : public Hero
{
public:
    Monk();
    std::string getClassName() const final;
};


#endif //TURN_BASED_GAME_MONK_H
