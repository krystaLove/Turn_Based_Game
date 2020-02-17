#include "Peasant.h"
#include "../Strikes/MeleeStrike.h"

Peasant::Peasant() : Hero(25, 0, 10, 10, 10, 30) {
    m_Strike = std::make_shared<MeleeStrike>(
            MeleeStrike(getDamage(), getPosition(), Strike::StrikeType::Enemy, 1));
    m_Class = HeroClass::PEASANT;
}

std::string Peasant::getClassName() const {
    return "Peasant";
}
