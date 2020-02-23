#include "Archer.h"
#include "../Strikes/RangeStrike.h"

Archer::Archer(): Hero(50, 0, 25, 70, 40, 100) {
    m_Strike = std::make_shared<RangeStrike>(
            RangeStrike(getDamage(), getPosition(), Strike::StrikeType::Enemy, 1));
    m_Class = Class::ARCHER;
}

std::string Archer::getClassName() const{
    return "Archer";
}
