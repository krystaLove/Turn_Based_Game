#ifndef TURN_BASED_GAME_APPRENTICE_H
#define TURN_BASED_GAME_APPRENTICE_H


#include "../Hero.h"

class Apprentice
        : public Hero
{
public:
    Apprentice();
    virtual std::string getClassName() const;
};


#endif //TURN_BASED_GAME_APPRENTICE_H
