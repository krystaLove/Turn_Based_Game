#include "Apprentice.h"
#include "../../Strikes/HealStrike.h"

Apprentice::Apprentice() : Hero(35, 0, -15, 30, 40, 100)
{
    m_Strike = std::make_shared<HealStrike>(
            getDamage(), getPosition(), Strike::StrikeType::ALIAS, 4);
    m_Class = Class::APPRENTICE;
}

std::string Apprentice::getClassName() const
{
    return "Apprentice";
}
