#ifndef TURN_BASED_GAME_BATTLEFIELD_H
#define TURN_BASED_GAME_BATTLEFIELD_H

#include <vector>
#include <memory>

#include "../Model/Hero.h"

class BattleField {

public:
    enum Status{ALIAS = 110, ENEMY, EMPTY, DEAD};
    enum Mode{STATUS, HEROES};

    void changeMode();

    typedef std::vector<std::vector<int> > StatusMatrix;

    BattleField(const std::vector<std::shared_ptr<Hero> > & heroes_alias,
            const std::vector<std::shared_ptr<Hero> > &heroes_enemy);
    ~BattleField() = default;

    static char getCharForHero(int heroClass);

    void showLegend();

    void drawField();
    const StatusMatrix& getStatusMatrix() const;

private:
    StatusMatrix m_StatusField;
    StatusMatrix m_HeroField;
    Mode m_Mode;
    std::vector<std::shared_ptr<Hero> > m_Heroes_Alias, m_Heroes_Enemy;

    void _refreshField();
    void _drawStatusField();
    void _drawHeroField();
};


#endif //TURN_BASED_GAME_BATTLEFIELD_H
