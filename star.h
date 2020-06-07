#ifndef STAR_H
#define STAR_H

#include <tuple>
#include <ncurses.h>
#include <thread>

class Star {
    public:
        Star(int x, bool isBonus, int speed, int id);
        ~Star();
        std::tuple<int, int> GetCoords();
        bool IsBonus();
        void Move();
        bool isClaimed();
        void Claim();

    private:
        int _x, _y, _speed, _id;
        bool _isBonus;
        bool _isClaimed = false;

};

#endif