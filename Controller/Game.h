#ifndef TURN_BASED_GAME_GAME_H
#define TURN_BASED_GAME_GAME_H


#include <memory>
#include "../Model/Player.h"

class Game {
private:
    enum MENU_OPTION{START = 1, MANAGE = 2, EXIT};
    bool m_Run;
    void showMainMenu();

    std::vector<std::shared_ptr<Player> > m_Players;

public:
    Game();
    ~Game() = default;

    void run();
    void update();
};


#endif //TURN_BASED_GAME_GAME_H
