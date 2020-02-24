#include "Inquisitor.h"
#include "../../Strikes/MeleeStrike.h"

Inquisitor::Inquisitor() : Hero(110, 20, -25, 40, 300, 150)
{
    m_Strike = std::make_shared<MeleeStrike> (
            getDamage(), getPosition(), Strike::StrikeType::ENEMY, 2);

    m_Class = Hero::Class::INQUISITOR;
}

std::string Inquisitor::getClassName() const
{
    return "Inquisitor";
}

