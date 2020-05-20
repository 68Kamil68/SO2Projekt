#include <ncurses.h>
#include <unistd.h>
#include <vector>
#include <thread>
#include "star.h"
using namespace std;

int main(int argc, char ** argv) {

    vector<thread> star_threads;
    vector<Star*> stars;

    initscr();
    int h, w, y, x;
    h=50;
    w=20;
    y=5;
    x=10;
    bool bonus = true;
    stars.push_back(new Star(h, bonus, y));

    WINDOW *window = newwin(h, w, y, x);
    
    refresh();

    box(window, 0, 0);
    wrefresh(window);

    int c =getch();

    endwin();

    return 0;
}
