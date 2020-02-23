#ifndef TURN_BASED_GAME_TEAMMANAGER_H
#define TURN_BASED_GAME_TEAMMANAGER_H

#include <vector>
#include "../Model/Player.h"

class TeamManager{
private:
    enum class MENU_TYPE{CONSTRUCT = 1, SHOW, ADD, REMOVE, EXIT};

    std::vector<std::shared_ptr<Player> > m_Players;
    bool m_Run;

    void _showMenu();

    //Menu options
    void _addRandomHero(int player_id);
    void _removeHero(int player_id);
    void _constructTeam(int player_id);

public:
    TeamManager(std::vector<std::shared_ptr<Player> > & players);
    ~TeamManager() = default;

    void run();
    void update();
};


#endif //TURN_BASED_GAME_TEAMMANAGER_H
