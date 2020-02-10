#include "Player.h"

#include <algorithm>

void Player::addHero(std::shared_ptr<Hero>& hero) {
    m_Heroes.push_back(hero);
    refreshOrder();
}

void Player::refreshOrder() {
    while(!m_Initiative_Order.empty())
        m_Initiative_Order.pop();

    std::vector<int> ids;
    for(int i = 0; i < m_Heroes.size(); ++i) ids.push_back(i);

    for(int i = 0; i < ids.size() - 1; ++i)
    {
        for(int j = i + 1; j < ids.size(); ++j)
        {
            if(Hero::compareByInitiative(m_Heroes[ids[i]], m_Heroes[ids[j]]) < 0)
            {
                std::swap(ids[i], ids[j]);
            }
        }
    }

    for(auto id: ids)
    {
        m_Initiative_Order.push(id);
    }
}

std::shared_ptr<Hero> Player::getNextTurnHero() {
    if(m_Initiative_Order.empty()) return nullptr;
    int id = m_Initiative_Order.front();
    m_Initiative_Order.pop();
    std::shared_ptr<Hero> &cur = m_Heroes[id];
    if(cur->isAlive())
    {
        m_Initiative_Order.push(id);
        return cur;
    }
    return getNextTurnHero();

}

const std::shared_ptr<Hero> &Player::getHeroById(int id) {
    return m_Heroes.at(id);
}
void Player::showQueue()
{
    std::queue<int> tmp = m_Initiative_Order;
    while(!tmp.empty())
    {
        std::cout << tmp.front() << " ";
        tmp.pop();
    }
}

const std::vector<std::shared_ptr<Hero> > &Player::getPlayerTeam() const {
    return m_Heroes;
}

void Player::showShortInfo() {
    for(int i = 0; i < m_Heroes.size(); ++i)
    {
        printf("[%d]: ", i);
        m_Heroes[i]->showShortInfo();
    }
}
