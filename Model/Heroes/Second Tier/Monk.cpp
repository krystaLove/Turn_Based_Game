#include "Monk.h"
#include "../../Strikes/HealStrike.h"

Monk::Monk() : Hero(20, 0, -20, 0, 40, 300)
{
    m_Strike = std::make_shared<HealStrike>(
            getDamage(), getPosition(), Strike::StrikeType::ALIAS, 1);
    m_Class = Hero::Class::MONK;
}

std::string Monk::getClassName() const {
    return "Monk";
}

