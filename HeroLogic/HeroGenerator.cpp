#include "HeroGenerator.h"
#include "../Model/Heroes/Archer.h"
#include "../Model/Heroes/Apprentice.h"
#include "../Model/Heroes/Swordsman.h"
#include "../Model/Heroes/Peasant.h"
#include "../Configs/GameConfig.h"
#include "../Utils/Console.h"

std::shared_ptr<Hero> HeroGenerator::generateHero(int type) {
    switch (type)
    {
        case Hero::HeroClass::ARCHER:
            return std::make_shared<Archer>(Archer());
        case Hero::HeroClass::APPRENTICE:
            return std::make_shared<Apprentice>(Apprentice());
        case Hero::HeroClass::SWORDSMAN:
            return std::make_shared<Swordsman>(Swordsman());
        case Hero::HeroClass::PEASANT:
            return std::make_shared<Peasant>(Peasant());
    }
}

std::shared_ptr<Hero> HeroGenerator::generateRandomHero() {
    int random = rand() % (Hero::HeroClass::SWORDSMAN + 1);
    return generateHero(random);
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
