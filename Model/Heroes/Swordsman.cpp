#include "Swordsman.h"
#include "../Strikes/MeleeStrike.h"

Swordsman::Swordsman() : Hero(100, 0, 25, 50){
    m_Strike = std::make_shared<MeleeStrike>(MeleeStrike(getDamage(), getPosition()));
}

std::string Swordsman::getClassName() const {
    return "Swordsman";
}
