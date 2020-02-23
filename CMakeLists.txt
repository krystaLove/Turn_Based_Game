cmake_minimum_required(VERSION 3.14)
project(Turn_Based_Game)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-D _WIN32")

add_executable(Turn_Based_Game main.cpp Model/Hero.cpp Model/Hero.h Utils/Console.cpp Utils/Console.h Model/Position.cpp Model/Position.h Model/Strikes/MeleeStrike.cpp Model/Strikes/MeleeStrike.h Model/Strikes/RangeStrike.cpp Model/Strikes/RangeStrike.h Model/Heroes/Peasant.cpp Model/Heroes/Peasant.h Model/Heroes/Archer.cpp Model/Heroes/Archer.h Model/Strikes/HealStrike.cpp Model/Strikes/HealStrike.h Model/Heroes/Apprentice.cpp Model/Heroes/Apprentice.h Model/Heroes/Swordsman.cpp Model/Heroes/Swordsman.h Controller/Game.cpp Controller/Game.h Model/Player.cpp Model/Player.h Controller/TeamManager.cpp Controller/TeamManager.h Utils/MenuUtils.cpp Utils/MenuUtils.h Configs/GameConfig.h Controller/BattleController.cpp Controller/BattleController.h Controller/BattleField.cpp Controller/BattleField.h HeroLogic/HeroGenerator.cpp HeroLogic/HeroGenerator.h HeroLogic/LevelUp.cpp HeroLogic/LevelUp.h Model/Strike.cpp Model/Strike.h)