#ifndef TURN_BASED_GAME_GUNNER_H
#define TURN_BASED_GAME_GUNNER_H


#include "../../Hero.h"

class Gunner
        : public Hero
{
public:
    Gunner();
    std::string getClassName() const override;
};


#endif //TURN_BASED_GAME_GUNNER_H
