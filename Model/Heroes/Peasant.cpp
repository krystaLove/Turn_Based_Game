#include "Peasant.h"
#include "../Strikes/MeleeStrike.h"

Peasant::Peasant() : Hero(25, 0, 10, 10) {
    m_Strike = std::make_shared<MeleeStrike>(MeleeStrike(getDamage(), getPosition()));
    m_Class = HeroClass::PEASANT;
}

std::string Peasant::getClassName() const {
    return "Peasant";
}
