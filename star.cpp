#include "star.h"

Star::Star(int x, bool isBonus, int speed) {
    _x = x;
    _isBonus = isBonus;
    _speed = speed;
}

void Star:: Move() {
    _y = _y - _speed;
}
