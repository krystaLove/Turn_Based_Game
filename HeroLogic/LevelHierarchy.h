#ifndef TURN_BASED_GAME_LEVELHIERARCHY_H
#define TURN_BASED_GAME_LEVELHIERARCHY_H

#include <map>
#include "HeroGenerator.h"

class LevelHierarchy {
private:
    std::map<Hero::Class, std::vector<Hero::Class> > m_HeroHierarchy;
    void _initHierarchy();
public:
    LevelHierarchy();

    std::vector<Hero::Class>& getWaysToLevelUp(Hero::Class hero);
};


#endif //TURN_BASED_GAME_LEVELHIERARCHY_H
