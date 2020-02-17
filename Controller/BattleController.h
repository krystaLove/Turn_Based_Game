#ifndef TURN_BASED_GAME_BATTLECONTROLLER_H
#define TURN_BASED_GAME_BATTLECONTROLLER_H


#include <vector>
#include "../Model/Player.h"
#include "BattleField.h"

class BattleController {

private:
    enum MENU_OPTION{ATTACK = 1, DEFEND, ORDER, LEGEND, CHANGE_MODE, INFO, EXIT};
    bool m_Run;

    int m_CurrentPlayer;
    int m_Turn;

    std::shared_ptr<BattleField> m_BattleField;

    std::vector< std::shared_ptr<Player> > m_Players;
    std::vector< std::pair< std::shared_ptr<Hero>, int> > m_HeroOrder;

    std::pair<std::shared_ptr<Hero>, int> &_getCurrentTurnHero();

    //Init
    void _initOrder();
    void _initPositions();

    //Menu
    void _showMenu();

    //Info
    void _showBattleInfo();
    void _showOrder();



public:
    BattleController(std::vector< std::shared_ptr<Player> > & players);
    ~BattleController() = default;

    void run();
    void update();

};


#endif //TURN_BASED_GAME_BATTLECONTROLLER_H
