#include "Player.h"

void Player::addHero(std::shared_ptr<Hero> hero) {
    m_Heroes.push_back(hero);
}

const std::shared_ptr<Hero> &Player::getHeroById(int id)
{
    return m_Heroes.at(id);
}

const std::vector<std::shared_ptr<Hero> > &Player::getPlayerTeam() const
{
    return m_Heroes;
}

const std::string &Player::getName() const
{
    return m_Name;
}

void Player::setName(std::string name)
{
    m_Name = name;
}

bool Player::isPlayerReady() {
    if(m_Heroes.empty()){
        std::cout << m_Name << " have no heroes in the team!" << std::endl;
        return false;
    }
    return true;
}

bool Player::isHavingHeroes()
{
    return !m_Heroes.empty();
}

int Player::getTeamSize() const
{
    return m_Heroes.size();
}

void Player::removeHero(int id)
{
    if(id < 0 || id >= m_Heroes.size()) return;
    m_Heroes.erase(m_Heroes.begin() + id);
}

void Player::removeTeam()
{
    m_Heroes.clear();
}

void Player::setTeam(const std::vector<std::shared_ptr<Hero> > team)
{
    for(auto &hero : team)
        m_Heroes.push_back(hero);
}

void Player::setHeroById(std::shared_ptr<Hero> &hero, int id)
{
    if(id < 0 || id >= m_Heroes.size()) return;
    m_Heroes[id] = hero;
}

void Player::showShortInfo()
{

    std::cout << "[ " << m_Name << "'s team info ]" << std::endl;
    std::cout << std::endl;

    if(!isHavingHeroes())
    {
        std::cout << "No heroes in the team!" << std::endl << std::endl;
        return;
    }

    for(int i = 0; i < m_Heroes.size(); ++i)
    {
        std::cout << "[" << i << "]: ";
        m_Heroes[i]->showShortInfo();
    }
    std::cout << std::endl;
}
