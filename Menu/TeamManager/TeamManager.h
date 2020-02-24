#ifndef TURN_BASED_GAME_TEAMMANAGER_H
#define TURN_BASED_GAME_TEAMMANAGER_H

#include <vector>
#include "../../Model/Player.h"

class TeamManager
{
public:
    TeamManager(std::vector<std::shared_ptr<Player> > & players);
    ~TeamManager() = default;

    void run();
    void update();

private:
    enum class MENU_TYPE{CONSTRUCT = 1, SHOW, ADD, REMOVE, ENCYCLOPEDIA, EXIT};

    std::vector<std::shared_ptr<Player> > m_Players;
    bool m_Run;

    void _showMenu();

    //Menu options
    void _addRandomHero(int player_id);
    void _removeHero(int player_id);
    void _constructTeam(int player_id);

};


#endif //TURN_BASED_GAME_TEAMMANAGER_H
