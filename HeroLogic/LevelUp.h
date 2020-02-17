#ifndef TURN_BASED_GAME_LEVELUP_H
#define TURN_BASED_GAME_LEVELUP_H

#include <map>
#include "HeroGenerator.h"

class LevelUp {
private:
    std::map<int, std::vector<int> > m_HeroHierarchy;
    void _initHierarchy();
public:
    LevelUp();
    ~LevelUp() = default;

    std::vector<int>& getWaysToLevelUp(int heroClass);
};


#endif //TURN_BASED_GAME_LEVELUP_H
