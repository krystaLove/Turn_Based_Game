#include "Swordsman.h"
#include "../../Strikes/MeleeStrike.h"

Swordsman::Swordsman() : Hero(100, 0, 25, 50, 40, 100){
    m_Strike = std::make_shared<MeleeStrike>(
            MeleeStrike(getDamage(), getPosition(), Strike::StrikeType::ENEMY, 1));
    m_Class = Class::SWORDSMAN;
}

std::string Swordsman::getClassName() const {
    return "Swordsman";
}
