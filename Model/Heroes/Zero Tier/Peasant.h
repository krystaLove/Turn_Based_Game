#ifndef TURN_BASED_GAME_PEASANT_H
#define TURN_BASED_GAME_PEASANT_H


#include "../../Hero.h"

class Peasant
        : public Hero
{
private:
public:
    Peasant();
    std::string getClassName() const final;
};


#endif //TURN_BASED_GAME_PEASANT_H
