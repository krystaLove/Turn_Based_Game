#include "Gunner.h"
#include "../../Strikes/RangeStrike.h"

Gunner::Gunner() : Hero(60, 0, 30, 60, 300, 200)
{
    m_Strike = std::make_shared<RangeStrike> (
            getDamage(), getPosition(), Strike::StrikeType::ALIAS, 2);
    m_Class = Hero::Class::GUNNER;
}

std::string Gunner::getClassName() const
{
    return "Gunner";
}

