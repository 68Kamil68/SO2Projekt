#include "star.h"

Star::Star(int x, bool isBonus, int speed, int id) {
    _x = x;
    _isBonus = isBonus;
    _speed = speed;
    _id = id;
    _y = 1;
}

void Star:: Move() {
    _y +=  1;
}

bool Star:: IsBonus() {
    if (_isBonus)
    {
        return true;
    } else
    {
        return false;
    }
      
}

std::tuple<int, int> Star:: GetCoords() {
    return std::make_tuple(_y, _x);
}