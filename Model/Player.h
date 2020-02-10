#ifndef TURN_BASED_GAME_PLAYER_H
#define TURN_BASED_GAME_PLAYER_H

#include <vector>
#include <queue>
#include "Hero.h"

class Player {
private:
    std::vector< std::shared_ptr<Hero> > m_Heroes;
    std::queue<int> m_Initiative_Order;
public:
    Player() = default;
    ~Player() = default;

    void addHero(std::shared_ptr<Hero>& hero);
    std::shared_ptr<Hero> getNextTurnHero();
    const std::shared_ptr<Hero>& getHeroById(int id);

    //Getters
    const std::vector< std::shared_ptr<Hero> >& getPlayerTeam() const;

    //Info
    void showShortInfo();
    void refreshOrder();
    void showQueue();

};


#endif //TURN_BASED_GAME_PLAYER_H
