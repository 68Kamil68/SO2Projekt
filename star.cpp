#include "star.h"

Star::Star(int x, bool isBonus, int speed, int id) {
    _x = x;
    _isBonus = isBonus;
    _speed = speed;
    _id = id;
}

void Star:: Move() {
    _y -=  _speed;
}

std::tuple<int, int> Star:: GetCoords() {
    return std::make_tuple(_x, _y);
}