#ifndef TURN_BASED_GAME_HERO_H
#define TURN_BASED_GAME_HERO_H

#pragma once

#include <vector>
#include <memory>

#include "Position.h"

class Strike;

class Hero {

public:
    enum class Class{NONE = -1, PEASANT = 0, APPRENTICE, ARCHER, SWORDSMAN};

    Hero(int health, int armor, int damage, int initiative, int exp_kill, int max_exp);
    virtual ~Hero() = default;

    //Getters
    int getHealth() const;
    int getArmor() const;
    int getDamage() const;
    int getInitiative() const;
    int getExperience() const;
    int getExperienceForKill() const;
    const std::shared_ptr<Position>& getPosition() const;
    Class getClass() const;

    bool canLevelUp() const;

    const std::shared_ptr<Strike>& getStrike();

    //Setters
    void setPosition(const std::shared_ptr<Position>&);
    void addExperience(int exp);
    void refreshHero();

    //Methods
    void attack(std::vector< std::shared_ptr<Hero> > & heroes);
    void setDefend(bool defence);
    void takeDamage(int damage);
    void move(Position& position);

    bool isAlive() const;

    //Info
    void showFullInfo() const;
    void showShortInfo() const;
    virtual std::string getClassName() const = 0;
    static std::string getClassName(Class type);

private:
    int m_Max_Health;
    int m_Max_Experience;

    int m_ExperienceForKill;

    int m_Health;
    int m_Armor;
    int m_Damage;
    int m_Initiative;
    int m_Experience;

    std::shared_ptr<Position> m_Position;

    bool m_Defend;

protected:
    std::shared_ptr<Strike> m_Strike;
    Class m_Class;

};


#endif //TURN_BASED_GAME_HERO_H
