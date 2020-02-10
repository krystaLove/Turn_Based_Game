#include "Apprentice.h"
#include "../Strikes/HealStrike.h"

Apprentice::Apprentice() : Hero(35, 0, -15, 30){
    m_Strike = std::make_shared<HealStrike>(HealStrike(getDamage(), getPosition()));
}

std::string Apprentice::getClassName() const {
    return "Apprentice";
}
