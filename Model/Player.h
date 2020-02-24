#ifndef TURN_BASED_GAME_PLAYER_H
#define TURN_BASED_GAME_PLAYER_H

#include <vector>
#include <queue>
#include "Hero.h"

class Player {
private:
    std::string m_Name;
    std::vector< std::shared_ptr<Hero> > m_Heroes;

public:
    Player() = default;
    ~Player() = default;

    void addHero(std::shared_ptr<Hero> hero);
    const std::shared_ptr<Hero>& getHeroById(int id);

    //Getters
    const std::vector< std::shared_ptr<Hero> >& getPlayerTeam() const;
    const std::string& getName() const;
    int getTeamSize() const;

    //Setters
    void setName(std::string name);
    void setTeam(std::vector< std::shared_ptr<Hero> > team);
    void removeHero(int id);
    void setHeroById(std::shared_ptr<Hero> &hero, int id);
    void removeTeam();

    //Info
    void showShortInfo();
    bool isPlayerReady();
    bool isHavingHeroes();

};

#endif //TURN_BASED_GAME_PLAYER_H
