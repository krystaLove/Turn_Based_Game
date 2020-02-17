#ifndef TURN_BASED_GAME_TEAMMANAGER_H
#define TURN_BASED_GAME_TEAMMANAGER_H

#include <vector>
#include "../Model/Player.h"

class TeamManager{
private:
    enum TYPE {MANAGE = 1, RANDOM = 2};
    enum MENU_TYPE{CONSTRUCT = 1, SHOW, ADD, CHANGE, REMOVE, EXIT};

    std::vector<std::shared_ptr<Player> > m_Players;
    bool m_Run;

    void _showMenu();

    //Menu options
    void _addRandomHero(int player_id);
    void _removeHero(int player_id);
    void _constructTeam(int player_id);

public:
    TeamManager(std::vector<std::shared_ptr<Player> > & players);
    void run();
    void update();
};


#endif //TURN_BASED_GAME_TEAMMANAGER_H
