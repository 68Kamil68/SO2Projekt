#ifndef _PLAYER_H
#define _PLAYER_H

#include <tuple>
#include <ncurses.h>
class Player {
    public:
        Player(WINDOW * win, int y, int x, char c);
        std::tuple<int, int> GetCoords();
        void MoveUp();
        void MoveDown();
        void MoveLeft();
        void MoveRight();
        void display();
        int getMove();
        int xLoc, yLoc, xMax, yMax;
        char character;
        WINDOW * currentWindow;
};


#endif