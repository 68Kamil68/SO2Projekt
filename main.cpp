#include <ncurses.h>
#include "player.h"
#include <thread>
using namespace std;

int main(int argc, char ** argv)
{
    initscr();

    int h, w, startY, startX;
    h = 25;
    w = 90;
    startY = startX = 5;
    
    WINDOW * win = newwin(h, w, startY, startX);
    refresh();

    box(win, 0, 0);
    mvwprintw(win, 24, 35, "Falling asteroids game");
    wrefresh(win);

    Player * p =new Player(win, 15,15, '#');

    
    do
    {
        curs_set(0);
        p->display();
        wrefresh(win);
    } while(p->getMove()!='q');
    

    //int c = getch();

    endwin();

    return 0;
}