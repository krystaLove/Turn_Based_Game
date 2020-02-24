#include "LevelHierarchy.h"

void LevelHierarchy::_initHierarchy() {
    int beginClass = static_cast<int>(Hero::Class::PEASANT);
    int endClass = static_cast<int>(Hero::Class::INQUISITOR);

    for(int i = beginClass; i <= endClass; ++i)
    {
        m_HeroHierarchy.insert({static_cast<Hero::Class>(i), std::vector<Hero::Class>()});
    }

    m_HeroHierarchy.at(Hero::Class::PEASANT).push_back(Hero::Class::SWORDSMAN);
    m_HeroHierarchy.at(Hero::Class::PEASANT).push_back(Hero::Class::APPRENTICE);
    m_HeroHierarchy.at(Hero::Class::PEASANT).push_back(Hero::Class::ARCHER);

    m_HeroHierarchy.at(Hero::Class::SWORDSMAN).push_back(Hero::Class::KNIGHT);
    m_HeroHierarchy.at(Hero::Class::SWORDSMAN).push_back(Hero::Class::INQUISITOR);

    m_HeroHierarchy.at(Hero::Class::ARCHER).push_back(Hero::Class::GUNNER);

    m_HeroHierarchy.at(Hero::Class::APPRENTICE).push_back(Hero::Class::MONK);
}

LevelHierarchy::LevelHierarchy() {
    _initHierarchy();
}

std::vector<Hero::Class> &LevelHierarchy::getWaysToLevelUp(Hero::Class heroClass) {
    return m_HeroHierarchy.at(heroClass);
}
