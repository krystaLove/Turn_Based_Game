#include "HeroGenerator.h"
#include "../Model/Heroes/Archer.h"
#include "../Model/Heroes/Apprentice.h"
#include "../Model/Heroes/Swordsman.h"
#include "../Model/Heroes/Peasant.h"
#include "../Configs/GameConfig.h"
#include "../Utils/Console.h"

#include <random>

std::shared_ptr<Hero> HeroGenerator::generateHero(Hero::Class type) {
    switch (type)
    {
        case Hero::Class::ARCHER:
            return std::make_shared<Archer>(Archer());
        case Hero::Class::APPRENTICE:
            return std::make_shared<Apprentice>(Apprentice());
        case Hero::Class::SWORDSMAN:
            return std::make_shared<Swordsman>(Swordsman());
        case Hero::Class::PEASANT:
            return std::make_shared<Peasant>(Peasant());
        case Hero::Class::NONE:
            return std::make_shared<Peasant>(Peasant());
    }
}

std::shared_ptr<Hero> HeroGenerator::generateRandomHero() {
    int random = rand() % (static_cast<int>(Hero::Class::SWORDSMAN) + 1);
    return generateHero(static_cast<Hero::Class>(random));
}

std::vector<std::shared_ptr<Hero> > HeroGenerator::generateRandomTeam() {
    std::vector<std::shared_ptr<Hero> > heroes;
    for(int i = 0; i < MAX_HEROES_PER_PLAYER; ++i)
    {
        std::shared_ptr<Hero> hero = generateRandomHero();
        heroes.push_back(hero);
    }
    return heroes;
}

char HeroGenerator::getCharForHero(Hero::Class heroClass) {
    switch(heroClass)
    {
        case Hero::Class::SWORDSMAN:
            return 'S';
        case Hero::Class::APPRENTICE:
            return 'A';
        case Hero::Class::PEASANT:
            return 'P';
        case Hero::Class::ARCHER:
            return 'R';
        case Hero::Class::NONE:
            return '.';
    }
}

