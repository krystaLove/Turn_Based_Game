#ifndef TURN_BASED_GAME_HERO_H
#define TURN_BASED_GAME_HERO_H

#pragma once


#include "Strike.h"

class Hero {
private:
    int m_Health;
    int m_Armor;
    int m_Damage;
    int m_Initiative;

    bool m_Defend;

protected:
    Strike* strike;

public:
    //Const | Destr
    Hero(int health, int armor, int damage, int initiative);
    virtual ~Hero() = default;

    //Getters
    int getHealth() const;
    int getArmor() const;
    int getDamage() const;
    int getInitiative() const;

    bool isAlive() const;
};


#endif //TURN_BASED_GAME_HERO_H
