#ifndef STAR_H
#define STAR_H

#include <tuple>
#include <ncurses.h>

class Star {
    public:
        Star(int x, bool isBonus, int speed);
        ~Star();
        std::tuple<int, int> GetCoords();
        bool IsBonus();
        void Move();

    private:
        int _x, _y, _speed;
        bool _isBonus;

};

#endif