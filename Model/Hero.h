#ifndef TURN_BASED_GAME_HERO_H
#define TURN_BASED_GAME_HERO_H

#pragma once

#include <vector>
#include <memory>

#include "Position.h"

class Strike;

class Hero {
private:
    int MAX_HEALTH;

    int m_Health;
    int m_Armor;
    int m_Damage;
    int m_Initiative;
    int m_Experience;

    std::shared_ptr<Position> m_Position;

    bool m_Defend;

protected:
    std::shared_ptr<Strike> m_Strike;

public:
    //Const | Destr
    Hero(int health, int armor, int damage, int initiative);
    virtual ~Hero() = default;

    //Getters
    int getHealth() const;
    int getArmor() const;
    int getDamage() const;
    int getInitiative() const;
    const std::shared_ptr<Position>& getPosition() const;

    //Comparator
    static int compareByInitiative(const std::shared_ptr<Hero> & heroA, const std::shared_ptr<Hero> & heroB);

    //Setters
    void setPosition(const std::shared_ptr<Position>&);

    //Methods
    void attack(std::vector<Hero*> & heroes);
    void takeDamage(int damage);
    void move(Position& position);

    bool isAlive() const;

    //Info
    void showFullInfo() const;
    void showShortInfo() const;
    virtual std::string getClassName() const = 0;
};

class Strike {
protected:
    int m_Damage;
    std::shared_ptr<Position> m_Pos;
public:
    Strike(int damage, const std::shared_ptr<Position> & pos);
    virtual ~Strike() = default;

    virtual bool isAvailableForStrike(const std::shared_ptr<Hero> & hero) = 0;
    virtual void operator() (std::vector<Hero*> & heroes) = 0;
};


#endif //TURN_BASED_GAME_HERO_H
