#include "HeroGenerator.h"

#include "../Model/Heroes/Zero Tier/Peasant.h"

#include "../Model/Heroes/First Tier/Archer.h"
#include "../Model/Heroes/First Tier/Apprentice.h"
#include "../Model/Heroes/First Tier/Swordsman.h"

#include "../Model/Heroes/Second Tier/Monk.h"
#include "../Model/Heroes/Second Tier/Gunner.h"
#include "../Model/Heroes/Second Tier/Knight.h"
#include "../Model/Heroes/Second Tier/Inquisitor.h"

#include "../Configs/GameConfig.h"
#include "../Utils/Console.h"

std::shared_ptr<Hero> HeroGenerator::generateHero(Hero::Class type)
{
    switch (type)
    {
        case Hero::Class::NONE:
            return std::make_shared<Peasant>();

        case Hero::Class::ARCHER:
            return std::make_shared<Archer>();
        case Hero::Class::APPRENTICE:
            return std::make_shared<Apprentice>();
        case Hero::Class::SWORDSMAN:
            return std::make_shared<Swordsman>();
        case Hero::Class::PEASANT:
            return std::make_shared<Peasant>();

        case Hero::Class::GUNNER:
            return std::make_shared<Gunner>();
        case Hero::Class::KNIGHT:
            return std::make_shared<Knight>();
        case Hero::Class::MONK:
            return std::make_shared<Monk>();
        case Hero::Class::INQUISITOR:
            return std::make_shared<Inquisitor>();
    }
}

std::shared_ptr<Hero> HeroGenerator::generateRandomHero()
{
    int random = rand() % (static_cast<int>(Hero::Class::SWORDSMAN) + 1);
    return generateHero(static_cast<Hero::Class>(random));
}

std::vector<std::shared_ptr<Hero> > HeroGenerator::generateRandomTeam()
{
    std::vector<std::shared_ptr<Hero> > heroes;
    for(int i = 0; i < MAX_HEROES_PER_PLAYER; ++i)
    {
        std::shared_ptr<Hero> hero = generateRandomHero();
        heroes.push_back(hero);
    }
    return heroes;
}

char HeroGenerator::getCharForHero(Hero::Class heroClass)
{
    switch(heroClass)
    {
        case Hero::Class::NONE:
            return '.';

        case Hero::Class::PEASANT:
            return 'P';

        case Hero::Class::SWORDSMAN:
            return 'S';
        case Hero::Class::APPRENTICE:
            return 'A';
        case Hero::Class::ARCHER:
            return 'R';

        case Hero::Class::GUNNER:
            return 'G';
        case Hero::Class::KNIGHT:
            return 'K';
        case Hero::Class::MONK:
            return 'M';
        case Hero::Class::INQUISITOR:
            return 'I';
    }
}

void HeroGenerator::showEncyclopedia()
{
    std::cout << "[ Tier 0 ]" << std::endl;
    generateHero(Hero::Class::PEASANT)->showShortInfo();

    std::cout << "\n[ Tier 1 ]" << std::endl;
    generateHero(Hero::Class::SWORDSMAN)->showShortInfo();
    generateHero(Hero::Class::APPRENTICE)->showShortInfo();
    generateHero(Hero::Class::ARCHER)->showShortInfo();

    std::cout << "\n[ Tier 2 ]" << std::endl;
    generateHero(Hero::Class::KNIGHT)->showShortInfo();
    generateHero(Hero::Class::INQUISITOR)->showShortInfo();
    generateHero(Hero::Class::MONK)->showShortInfo();
    generateHero(Hero::Class::GUNNER)->showShortInfo();

    std::cout << std::endl;
}

