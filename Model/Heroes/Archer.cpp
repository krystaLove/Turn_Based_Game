#include "Archer.h"
#include "../Strikes/RangeStrike.h"

Archer::Archer(): Hero(50, 0, 25, 70) {
    m_Strike = std::make_shared<RangeStrike>(RangeStrike(getDamage(), getPosition()));
    m_Class = HeroClass::ARCHER;
}

std::string Archer::getClassName() const{
    return "Archer";
}
