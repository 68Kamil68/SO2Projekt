#include <ncurses.h>
#include <unistd.h>
#include <vector>
#include <thread>
#include "star.h"
#include "engine.h"
using namespace std;


void initWindow() {
        initscr();
        noecho();
        curs_set(FALSE);
        clear();
        refresh();
}

void clearChar(int y, int x){
    mvdelch(y, x);
}

void drawStar(int y, int x){
    mvprintw(y, x, "*");
}

int main(int argc, char ** argv) {

    vector<thread> star_threads;

    initscr();
    int h, w, y, x;
    h=50;
    w=20;
    y=5;
    x=10;

    WINDOW *window = newwin(h, w, y, x);
    
    refresh();

    box(window, 0, 0);
    wrefresh(window);

    int c =getch();

    endwin();

    return 0;
}
