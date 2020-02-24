#ifndef TURN_BASED_GAME_LEVELUP_H
#define TURN_BASED_GAME_LEVELUP_H

#include "../Model/Player.h"

struct LevelUp
{
    static void levelUpPlayerTeam(std::shared_ptr<Player>& player);
};


#endif //TURN_BASED_GAME_LEVELUP_H
