#ifndef TURN_BASED_GAME_APPRENTICE_H
#define TURN_BASED_GAME_APPRENTICE_H


#include "../Hero.h"

class Apprentice
        : public Hero
{
public:
    Apprentice();
    std::string getClassName() const final;
};


#endif //TURN_BASED_GAME_APPRENTICE_H
