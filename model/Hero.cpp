#include "Hero.h"

Hero::Hero(int health, int armor, int damage, int initiative)
{
    m_Health = health;
    m_Armor = armor;
    m_Damage = damage;
    m_Initiative = initiative;
    m_Defend = false;
}

//Getters

int Hero::getHealth() const     { return m_Health;      }
int Hero::getArmor() const      { return m_Armor;       }
int Hero::getDamage() const     { return m_Damage;      }
int Hero::getInitiative() const { return m_Initiative;  }

bool Hero::isAlive() const {
    return m_Health > 0;
}

