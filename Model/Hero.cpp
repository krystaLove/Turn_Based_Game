#include "Hero.h"
#include "Strikes/RangeStrike.h"

//Hero abstract class

const int MAX_ARMOR = 100;

Hero::Hero(int health, int armor, int damage, int initiative)
{
    MAX_HEALTH = health;

    m_Health = health;
    m_Armor = armor;
    m_Damage = damage;
    m_Initiative = initiative;
    m_Defend = false;
    m_Position = nullptr;

    m_Experience = 0;
    m_Position = std::make_shared<Position>(Position(-1, -1));
    m_Strike = std::make_shared<RangeStrike>(RangeStrike(m_Damage, m_Position));
}

//Getters

int Hero::getHealth() const     { return m_Health;      }
int Hero::getArmor() const      { return m_Armor;       }
int Hero::getDamage() const     { return m_Damage;      }
int Hero::getInitiative() const { return m_Initiative;  }

const std::shared_ptr<Position>& Hero::getPosition() const {
    return m_Position;
}

bool Hero::isAlive() const {
    return m_Health > 0;
}

void Hero::attack(std::vector<Hero *> &heroes) {
    m_Strike->operator()(heroes);
}

void Hero::takeDamage(int damage) {
    if(damage <= 0)
    {
        m_Health -= damage;
        if(m_Health > MAX_HEALTH)
            m_Health = MAX_HEALTH;
        return;
    }
    float real_damage = static_cast<float>(damage);
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

int Hero::compareByInitiative(const std::shared_ptr<Hero> &heroA, const std::shared_ptr<Hero> &heroB) {
    return heroA->getInitiative() - heroB->getInitiative();
}

void Hero::showShortInfo() const{
    printf("[CL: %12s, HP: %3d, AR: %3d, DMG: %3d, INIT: %3d]\n", getClassName().c_str(), getHealth(), getArmor(), getDamage(), getInitiative());
}

//Strike abstract class

Strike::Strike(int damage, const std::shared_ptr<Position> & pos) {
    m_Damage = damage;
    m_Pos = pos;
}
