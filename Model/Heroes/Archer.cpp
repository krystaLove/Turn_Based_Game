//
// Created by krystalove on 10.02.2020.
//

#include "Archer.h"
#include "../Strikes/RangeStrike.h"

Archer::Archer(): Hero(50, 0, 25, 70) {
    m_Strike = std::make_shared<RangeStrike>(RangeStrike(getDamage(), getPosition()));
}

std::string Archer::getClassName() const{
    return "Archer";
}
