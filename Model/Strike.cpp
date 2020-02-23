#include "Strike.h"

Strike::Strike(int damage, const std::shared_ptr<Position> & pos, StrikeType strikeType, int targets) {
    m_Damage = damage;
    m_Pos = pos;
    m_Targets = targets;
    m_StrikeType = strikeType;
}

Strike::CombatType Strike::getCombatType() {
    return m_CombatType;
}

int Strike::getTargets() {
    return m_Targets;
}