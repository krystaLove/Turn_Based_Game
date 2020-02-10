#ifndef TURN_BASED_GAME_STRIKE_H
#define TURN_BASED_GAME_STRIKE_H

#include <vector>
#include "Position.h"

class Strike {
private:
    int m_Damage;
    Position m_Pos;
public:
    virtual ~Strike() = default;
    Strike(int damage, Position pos);
    virtual void operator() (std::vector<Hero*> & heroes) = 0;
};


#endif //TURN_BASED_GAME_STRIKE_H
