#include "LevelUp.h"
#include "../HeroLogic/LevelHierarchy.h"
#include "../Utils/Console.h"
#include "../Utils/MenuUtils.h"


void LevelUp::levelUpPlayerTeam(std::shared_ptr<Player>& player) {

    LevelHierarchy levelHierarchy;
    auto &playerTeam = player->getPlayerTeam();

    for(int id = 0; id < playerTeam.size(); ++id)
    {
        Console::writeLine(" = Level Up = \n");

        auto &hero = playerTeam[id];
        if(!hero->canLevelUp()) continue;

        std::cout << "Your " << hero->getClassName() << " can level up!\n\n";

        auto waysToLevelUp = levelHierarchy.getWaysToLevelUp(hero->getClass());

        Console::writeLine("[ Transform ]\n");
        int it = 1;
        for(auto heroClass : waysToLevelUp)
        {
            std::cout << "[" << it++ << "]. " << Hero::getClassName(heroClass) << std::endl;
        }
        std::cout << "\n[" << it << "]. Decline\n";

        int pick = MenuUtils::getInput(1, it);
        if(pick > waysToLevelUp.size())
        {
            Console::clearScreen();
            continue;
        }

        Console::writeLine("\n[ Your Hero has transformed! ]");
        hero->showShortInfo();

        auto transformedHero = HeroGenerator::generateHero(waysToLevelUp[pick - 1]);
        player->setHeroById(transformedHero, id);

        Console::writeLine("\n [ Now ]");
        transformedHero->showShortInfo();

        Console::waitForPress();
        Console::clearScreen();
    }

}
