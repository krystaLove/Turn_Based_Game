#ifndef TURN_BASED_GAME_KNIGHT_H
#define TURN_BASED_GAME_KNIGHT_H


#include "../../Hero.h"

class Knight
        : public Hero
{
public:
    Knight();
    std::string getClassName() const final;
};


#endif //TURN_BASED_GAME_KNIGHT_H
