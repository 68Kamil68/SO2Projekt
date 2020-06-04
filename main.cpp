#include <ncurses.h>
#include "player.h"
#include "engine.h"
#include <thread>
using namespace std;

//branch counter_and_points
// git status, git add, git commit, git push origin (nazwa_brancha)

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

    Engine * engine = new Engine();

    while (true)
    {
        engine->GenerateStar();
        for(int i = 0; i < engine->stars.size(); i++) {
            Star * star = engine->stars.at(i);
            std::tuple<int, int> coords = star->GetCoords();
            mvwaddch(win, std::get<0>(coords), std::get<1>(coords), ' ');
            star->Move();
            coords = star->GetCoords();
            if(star->IsBonus()) {
                mvwaddch(win, std::get<0>(coords), std::get<1>(coords), '+');
            } else
            {
                mvwaddch(win, std::get<0>(coords), std::get<1>(coords), '*');
            }
            wrefresh(win);
        }
    }
       
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