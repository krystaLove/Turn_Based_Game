#include "Peasant.h"
#include "../../Strikes/MeleeStrike.h"

Peasant::Peasant() : Hero(25, 0, 1000, 10, 10, 30) {
    m_Strike = std::make_shared<MeleeStrike>(
            MeleeStrike(getDamage(), getPosition(), Strike::StrikeType::ENEMY, 1));
    m_Class = Class::PEASANT;
}

std::string Peasant::getClassName() const {
    return "Peasant";
}
