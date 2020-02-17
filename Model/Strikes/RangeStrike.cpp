#include <iostream>
#include "RangeStrike.h"

RangeStrike::RangeStrike(int damage, const std::shared_ptr<Position> & pos) : Strike(damage, pos) {

}

bool RangeStrike::isAvailableForStrike(const std::shared_ptr<Hero> &hero) {
    return abs(m_Pos->getX() - hero->getPosition()->getX()) + abs(m_Pos->getY() - hero->getPosition()->getY()) > 1;
}

void RangeStrike::operator()(std::vector<Hero *> &heroes) {
    std::cerr << "Range Attack" << std::endl;
    std::cerr << *m_Pos << std::endl;
}

std::vector<std::shared_ptr<Hero> > RangeStrike::getAvailableHeroesForStrike(std::vector<std::vector<int> > matrix, std::vector<std::shared_ptr<Hero> > heroes)
{
    std::vector<std::shared_ptr<Hero> > availableForStrike;
    //std::vector<std::vector<bool> > allowedPlacesForStrike(matrix.size(), std::vector<bool>(matrix[0].size()));

    for(auto const &hero : heroes)
    {
        availableForStrike.push_back(hero);
    }
    return availableForStrike;
}
