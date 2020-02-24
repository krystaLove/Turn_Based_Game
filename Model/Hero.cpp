#include "Hero.h"
#include "Strikes/Strike.h"

//Hero abstract class

const int MAX_ARMOR = 100;

Hero::Hero(int health, int armor, int damage, int initiative, int exp_kill, int max_exp)
{
    m_Max_Health = health;
    m_Max_Experience = max_exp;

    m_ExperienceForKill = exp_kill;

    m_Health = health;
    m_Armor = armor;
    m_Damage = damage;
    m_Initiative = initiative;
    m_Defend = false;
    m_Position = nullptr;

    m_Experience = 0;
    m_Position = std::make_shared<Position>(0, 0);
    m_Strike = nullptr;
    m_Class = Class::NONE;

    std::cout << "Hero created!\n";
}

//Getters

int Hero::getHealth() const {return m_Health;}
int Hero::getArmor() const {return m_Armor;}
int Hero::getDamage() const {return m_Damage;}
int Hero::getInitiative() const {return m_Initiative;}

const std::shared_ptr<Position>& Hero::getPosition() const {return m_Position;}

bool Hero::isAlive() const {return m_Health > 0;}

void Hero::attack(std::vector< std::shared_ptr<Hero> > & heroes) {
    m_Strike->operator()(heroes);
}

void Hero::takeDamage(int damage) {
    if(damage <= 0)
    {
        m_Health -= damage;
        if(m_Health > m_Max_Health)
            m_Health = m_Max_Health;
        return;
    }
    auto real_damage = static_cast<float>(damage);
    if(m_Defend) real_damage /= 2;
    real_damage -= (real_damage / MAX_ARMOR) * static_cast<float>(m_Armor);
    m_Health -= static_cast<int>(real_damage);
}

void Hero::setPosition(const std::shared_ptr<Position> & pos) {
    m_Position = pos;
}

void Hero::move(Position &position) {
    m_Position->setX(position.getX());
    m_Position->setY(position.getY());
}

void Hero::showFullInfo() const{
    std::cout << "[Class: " << getClassName() << "]\n";
    std::cout << "[Health: " << getHealth() << "]\n";
    std::cout << "[Armor: " << getArmor() << "]\n";
    std::cout << "[Damage: " << getDamage() << "]\n";
    std::cout << "[Initiative: " << getInitiative() << "]\n";
}

void Hero::showShortInfo() const{
    std::string strikeType;

    switch(m_Strike->getCombatType())
    {
        case Strike::CombatType::Melee:
        {
            strikeType = "Melee";
            break;
        }
        case Strike::CombatType::Heal:
        {
            strikeType = "Heal";
            break;
        }
        case Strike::CombatType::Range:
        {
            strikeType = "Range";
            break;
        }
    }

    printf("[CL: %7s, HP: %3d, AR: %3d, DMG: %3d, INIT: %3d, STRIKE: %6s]\n",
            getClassName().c_str(), getHealth(), getArmor(), getDamage(), getInitiative(), strikeType.c_str());
}

Hero::Class Hero::getClass() const{
    return m_Class;
}

std::string Hero::getClassName(Hero::Class type) {
    switch(type)
    {
        case Class::ARCHER:
            return "Archer";
        case Class::PEASANT:
            return "Peasant";
        case Class::SWORDSMAN:
            return "Swordsman";
        case Class::APPRENTICE:
            return "Apprentice";
    }
}

void Hero::setDefend(bool defence) {
    m_Defend = defence;
}

const std::shared_ptr<Strike> &Hero::getStrike() {
    return m_Strike;
}

int Hero::getExperience() const {
    return m_Experience;
}

bool Hero::canLevelUp() const {
    return m_Experience >= m_Max_Experience;
}

void Hero::addExperience(const int exp) {
    m_Experience += exp;
    m_Experience = m_Experience > m_Max_Experience ? m_Max_Experience : m_Experience;
}

int Hero::getExperienceForKill() const {
    return m_ExperienceForKill;
}

void Hero::refreshHero() {
    m_Defend = false;
    m_Health = m_Max_Health;
}
