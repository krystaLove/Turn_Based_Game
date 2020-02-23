#include "LevelUp.h"

void LevelUp::_initHierarchy() {
    m_HeroHierarchy.insert({Hero::Class::SWORDSMAN, std::vector<Hero::Class>()});
    m_HeroHierarchy.insert({Hero::Class::ARCHER, std::vector<Hero::Class>()});
    m_HeroHierarchy.insert({Hero::Class::APPRENTICE, std::vector<Hero::Class>()});
    m_HeroHierarchy.insert({Hero::Class::PEASANT, std::vector<Hero::Class>()});

    m_HeroHierarchy.at(Hero::Class::PEASANT).push_back(Hero::Class::SWORDSMAN);
    m_HeroHierarchy.at(Hero::Class::PEASANT).push_back(Hero::Class::APPRENTICE);
    m_HeroHierarchy.at(Hero::Class::PEASANT).push_back(Hero::Class::ARCHER);
}

LevelUp::LevelUp() {
    _initHierarchy();
}

std::vector<Hero::Class> &LevelUp::getWaysToLevelUp(Hero::Class heroClass) {
    return m_HeroHierarchy.at(heroClass);
}
