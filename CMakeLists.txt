cmake_minimum_required(VERSION 3.15)
project(Turn_Based_Game)

set(CMAKE_CXX_STANDARD 17)

add_executable(Turn_Based_Game main.cpp model/Hero.cpp model/Hero.h Console.cpp Console.h model/Strike.cpp model/Strike.h model/Position.cpp model/Position.h)