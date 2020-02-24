#ifndef TURN_BASED_GAME_INQUISITOR_H
#define TURN_BASED_GAME_INQUISITOR_H


#include "../../Hero.h"

class Inquisitor
        : public Hero
{
public:
    Inquisitor();
    std::string getClassName() const override;
};


#endif //TURN_BASED_GAME_INQUISITOR_H
