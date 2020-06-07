#include "star.h"

Star::Star(int x, bool isBonus, int speed, int id) {
    _x = x;
    _isBonus = isBonus;
    _speed = speed;
    _id = id;
    _y = 1;
}

Star::~Star() {}

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

bool Star::isClaimed(){
    return _isClaimed;
}

void Star::Claim() {
    _isClaimed = true;
}
std::tuple<int, int> Star:: GetCoords() {
    return std::make_tuple(_y, _x);
}