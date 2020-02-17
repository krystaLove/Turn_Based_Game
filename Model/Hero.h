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
    int MAX_EXPERIENCE;

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
    int m_Class;

public:
    enum HeroClass{PEASANT = 0, APPRENTICE, ARCHER, SWORDSMAN};

    //Const | Destr
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
    int getClass() const;

    bool canLevelUp() const;

    const std::shared_ptr<Strike>& getStrike();

    //Setters
    void setPosition(const std::shared_ptr<Position>&);
    void addExperience(const int exp);
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
    static std::string getClassName(HeroClass type);
};

class Strike {
public:
    enum CombatType {Melee, Range, Heal};
    enum StrikeType {Alias, Enemy};

    Strike(int damage, const std::shared_ptr<Position> & pos, StrikeType strikeType, int targets);
    virtual ~Strike() = default;

    CombatType getCombatType();
    int getTargets();

    virtual std::vector<std::shared_ptr<Hero> > getAvailableHeroesForStrike(std::vector<std::vector<int> > matrix,
            std::vector<std::shared_ptr<Hero> >) = 0;
    virtual bool isAvailableForStrike(const std::shared_ptr<Hero> & hero) = 0;
    virtual int operator() (std::vector< std::shared_ptr<Hero> > & heroes) = 0;

protected:
    int m_Damage;
    std::shared_ptr<Position> m_Pos;
    CombatType m_CombatType;
    StrikeType m_StrikeType;
    int m_Targets;
};


#endif //TURN_BASED_GAME_HERO_H
