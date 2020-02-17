#include "LevelUp.h"

void LevelUp::_initHierarchy() {
    m_HeroHierarchy.insert({Hero::HeroClass::SWORDSMAN, std::vector<int>()});
    m_HeroHierarchy.insert({Hero::HeroClass::ARCHER, std::vector<int>()});
    m_HeroHierarchy.insert({Hero::HeroClass::APPRENTICE, std::vector<int>()});
    m_HeroHierarchy.insert({Hero::HeroClass::PEASANT, std::vector<int>()});

    m_HeroHierarchy.at(Hero::HeroClass::PEASANT).push_back(Hero::HeroClass::SWORDSMAN);
    m_HeroHierarchy.at(Hero::HeroClass::PEASANT).push_back(Hero::HeroClass::APPRENTICE);
    m_HeroHierarchy.at(Hero::HeroClass::PEASANT).push_back(Hero::HeroClass::ARCHER);
}

LevelUp::LevelUp() {
    _initHierarchy();
}

std::vector<int> &LevelUp::getWaysToLevelUp(int heroClass) {
    return m_HeroHierarchy.at(heroClass);
}
