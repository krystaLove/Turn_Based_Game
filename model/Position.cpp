#include "Position.h"

Position::Position(int x, int y) {
    m_Position = {x, y};
}

Position::Position(std::pair<int, int> pos) {
    m_Position = pos;
}

int Position::getX() const {
    return m_Position.first;
}

int Position::getY() const {
    return m_Position.second;
}

std::pair<int, int> Position::getPosition() const {
    return m_Position;
}

void Position::setPosition(std::pair<int, int> pos) {
    m_Position = pos;
}

void Position::setY(int y) {
    m_Position.second = y;
}

void Position::setX(int x) {
    m_Position.first = x;
}

Position Position::operator=(Position pos) {
    return pos;
}
