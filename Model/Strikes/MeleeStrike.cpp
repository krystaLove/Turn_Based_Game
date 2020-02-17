#include <iostream>
#include "MeleeStrike.h"
#include "../../Controller/BattleField.h"

MeleeStrike::MeleeStrike(int damage, const std::shared_ptr<Position>& pos) : Strike(damage, pos) {

}

std::vector<std::shared_ptr<Hero> > MeleeStrike::getAvailableHeroesForStrike(std::vector<std::vector<int> > matrix, std::vector<std::shared_ptr<Hero> > heroes)
{
    std::vector<std::shared_ptr<Hero> > availableForStrike;
    //std::vector<std::vector<bool> > allowedPlacesForStrike(matrix.size(), std::vector<bool>(matrix[0].size()));

    int cur_x = m_Pos->getX();
    int cur_y = m_Pos->getY();

    /*for(int dx = cur_x; cur_x < matrix.size(); cur_x++){
        if(matrix[dx][cur_y] == BattleField::Status::get)
    }*/
    for(auto const &hero : heroes)
    {

        availableForStrike.push_back(hero);
    }
    return availableForStrike;
}

void MeleeStrike::operator()(std::vector<Hero *> &heroes) {
    for(auto hero : heroes)
    {
        int prev_hp = hero->getHealth();
        hero->takeDamage(m_Damage);
        std::cout << "Hero slain " << hero->getClassName() << " for " << prev_hp - hero->getHealth();
        std::cout << "(" << hero->getHealth() << ")" << "HP!\n";
    }
}

bool MeleeStrike::isAvailableForStrike(const std::shared_ptr<Hero> &hero) {
    return true;
}
