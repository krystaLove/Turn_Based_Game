#ifndef TURN_BASED_GAME_BATTLEFIELD_H
#define TURN_BASED_GAME_BATTLEFIELD_H

#include <vector>
#include <memory>
#include "../../Model/Hero.h"

class BattleField {

public:
    enum class Status{ALIAS = 110, ENEMY, EMPTY, DEAD};
    enum class Mode{STATUS, HEROES};

    BattleField(const std::vector<std::shared_ptr<Hero> > & heroes_alias,
                const std::vector<std::shared_ptr<Hero> > &heroes_enemy);
    ~BattleField() = default;

    using StatusMatrix = std::vector<std::vector<Status> >;
    using HeroMatrix = std::vector<std::vector<Hero::Class> >;

    const StatusMatrix& getStatusMatrix() const;

    void showLegend();
    void drawField();
    void changeMode();

private:
    StatusMatrix m_StatusField;
    HeroMatrix m_HeroField;
    Mode m_Mode;
    std::vector<std::shared_ptr<Hero> > m_Heroes_Alias, m_Heroes_Enemy;

    void _refreshField();
    void _drawStatusField();
    void _drawHeroField();
};

#endif //TURN_BASED_GAME_BATTLEFIELD_H
