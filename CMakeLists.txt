cmake_minimum_required(VERSION 3.15)
project(Turn_Based_Game)

set(CMAKE_CXX_STANDARD 17)

add_executable(Turn_Based_Game main.cpp Model/Hero.cpp Model/Hero.h Utils/Console.cpp Utils/Console.h Model/Position.cpp Model/Position.h Model/Strikes/MeleeStrike.cpp Model/Strikes/MeleeStrike.h Model/Strikes/RangeStrike.cpp Model/Strikes/RangeStrike.h Model/Heroes/Peasant.cpp Model/Heroes/Peasant.h Model/Heroes/Archer.cpp Model/Heroes/Archer.h Model/Strikes/HealStrike.cpp Model/Strikes/HealStrike.h Model/Heroes/Apprentice.cpp Model/Heroes/Apprentice.h Model/Heroes/Swordsman.cpp Model/Heroes/Swordsman.h Controller/Game.cpp Controller/Game.h Model/Player.cpp Model/Player.h Controller/CreateTeamManager.cpp Controller/CreateTeamManager.h Utils/MenuUtils.cpp Utils/MenuUtils.h Configs/GameConfig.h)