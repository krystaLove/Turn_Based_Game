#ifndef TURN_BASED_GAME_CREATETEAMMANAGER_H
#define TURN_BASED_GAME_CREATETEAMMANAGER_H


#include <vector>
#include "../Model/Player.h"

class CreateTeamManager{
private:
    enum TYPE {MANAGE = 1, RANDOM = 2};
    enum MENU_TYPE{SHOW = 1, ADD, CHANGE, EXIT};

    std::vector<std::shared_ptr<Player> > m_Players;
    bool m_Run;

    void showMenu();

    void addRandomHero(int player_id);

public:
    CreateTeamManager(std::vector<std::shared_ptr<Player> > & players);
    void run();
    void update();
};


#endif //TURN_BASED_GAME_CREATETEAMMANAGER_H
