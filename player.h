#ifndef _PLAYER_H
#define _PLAYER_H

#include <tuple>

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

    Player::Player(WINDOW * win, int y , int x, char c)
    {
        currentWindow = win;
        yLoc = y;
        xLoc = x;
        getmaxyx(currentWindow, yMax, xMax);
        keypad(currentWindow, true);
        character = c;
    }

    void Player::MoveUp()
    {
        mvwaddch(currentWindow, yLoc, xLoc, ' ');
        yLoc --;
        if(yLoc <1)
            yLoc =1;

    }
    
    void Player::MoveDown()
    {
        mvwaddch(currentWindow, yLoc, xLoc, ' ');
        yLoc++;
        if(yLoc >yMax-2)
            yLoc =yMax -2;
    }

    void Player::MoveLeft()
    {
        mvwaddch(currentWindow, yLoc, xLoc, ' ');
        xLoc-=2;
        if(xLoc < 1)
            xLoc = 1;
    }

    void Player::MoveRight()
    {
        mvwaddch(currentWindow, yLoc, xLoc, ' ');
        xLoc+=2;
        if(xLoc > xMax-2)
            xLoc = xMax-2;
    }

    int Player::getMove()
    {
        int choice = wgetch(currentWindow);
        switch(choice)
        {
            case KEY_UP:
                MoveUp();
                break;
            case KEY_DOWN:
                MoveDown();
                break;
            case KEY_LEFT:
                MoveLeft();
                break;
            case KEY_RIGHT:
                MoveRight();
                break;
            default:
                break;
        }
        return choice;
    }

    void Player::display()
    {
        mvwaddch(currentWindow, yLoc, xLoc, character);
    }

#endif