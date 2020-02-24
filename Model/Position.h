#ifndef TURN_BASED_GAME_POSITION_H
#define TURN_BASED_GAME_POSITION_H

#include <utility>
#include <iostream>

class Position {
public:
    Position(std::pair<int, int> pos);
    Position(int x = 0, int y = 0);

    int getX() const;
    int getY() const;
    std::pair<int, int> getPosition() const;

    void setX(int x);
    void setY(int y);
    void setPosition(std::pair<int, int> pos);

    friend std::ostream& operator<<(std::ostream& os, const Position& pos);

private:
    std::pair<int, int> m_Position;
};

#endif //TURN_BASED_GAME_POSITION_H
