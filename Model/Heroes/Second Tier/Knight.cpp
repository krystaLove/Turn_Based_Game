#include "Knight.h"
#include "../../Strikes/MeleeStrike.h"

Knight::Knight() : Hero(150, 10, 40, 55, 100, 300)
{
    m_Strike = std::make_shared<MeleeStrike>(
            getDamage(), getPosition(), Strike::StrikeType::ENEMY, 1);
    m_Class = Class::KNIGHT;
}

std::string Knight::getClassName() const {
    return "Knight";
}

