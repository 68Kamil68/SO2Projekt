#ifndef SOPROJEKT_PLAYER_H
#define SOPROJEKT_PLAYER_H

#include <tuple>

class Player {
    public:
        Player();
        std::tuple<int, int> GetCoords();
        void Move();

    private:
        int CurrX, CurrY;
        int LastX, LastY;
        
};

#endif