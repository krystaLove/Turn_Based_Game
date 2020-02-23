#ifndef TURN_BASED_GAME_LEVELUP_H
#define TURN_BASED_GAME_LEVELUP_H

#include <map>
#include "HeroGenerator.h"

class LevelUp {
private:
    std::map<Hero::Class, std::vector<Hero::Class> > m_HeroHierarchy;
    void _initHierarchy();
public:
    LevelUp();
    ~LevelUp() = default;

    std::vector<Hero::Class>& getWaysToLevelUp(Hero::Class hero);
};


#endif //TURN_BASED_GAME_LEVELUP_H
