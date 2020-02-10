//
// Created by krystalove on 10.02.2020.
//

#ifndef TURN_BASED_GAME_POSITION_H
#define TURN_BASED_GAME_POSITION_H

#include <utility>

class Position {
private:
    std::pair<int, int> m_Position;
public:
    Position(std::pair<int, int> pos);
    Position(int x = 0, int y = 0);

    int getX() const;
    int getY() const;
    std::pair<int, int> getPosition() const;
    void setX(int x);
    void setY(int y);
    void setPosition(std::pair<int, int> pos);

    Position operator=(Position pos);
};


#endif //TURN_BASED_GAME_POSITION_H