#ifndef TURN_BASED_GAME_HEROGENERATOR_H
#define TURN_BASED_GAME_HEROGENERATOR_H


#include "../Model/Hero.h"

struct HeroGenerator {
    static std::shared_ptr<Hero> generateHero(Hero::Class);
    static std::shared_ptr<Hero> generateRandomHero();
    static std::vector<std::shared_ptr<Hero> > generateRandomTeam();

    static char getCharForHero(Hero::Class);
    static void showEncyclopedia();

};


#endif //TURN_BASED_GAME_HEROGENERATOR_H
