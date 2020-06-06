#include <ncurses.h>
#include <math.h>
#include "player.h"
#include "engine.h"
#include <thread>
#include <time.h>
#include <unistd.h>

using namespace std;

//branch counter_and_points
// git status, git add, git commit, git push origin (nazwa_brancha)




void Counter(WINDOW* counter_window, WINDOW* points_window) {
        
    int seconds = 0;
    int points = 0;
    int multiplier =1;
    int help = 1;
    int move =10;
    int mins = 0;
    const char *s = "sec";
    const char *m = "min";
    while (true)
    {   
        curs_set(0);
        wrefresh(counter_window);
        wrefresh(points_window);
        if(seconds>60)
        {
            mins++;
            seconds=0;
            mvwprintw(counter_window, 1, 5, "%dmin %dsec",mins, seconds);
        }
        else
        {
           mvwprintw(counter_window, 1, 5, "%dmin %dsec",mins, seconds);
        }
        
        if(seconds%10 == 0 && seconds!=0)
        {
            multiplier+=10;
            
        }

        if(points>=100*help && points <10000*help)
        {
            move-=1;
            help+=100;
            if(help == 101)
                help--;
            wclear(points_window);
            box(points_window, 0, 0);
            mvwprintw(points_window, 2, 7, "Points");
            
        }
        points=points+multiplier;
        seconds++;
        mvwprintw(points_window, 1, move, "%d", points);
        sleep(1);
    }
}

void GenerateStars(Engine* engine, WINDOW* win) {
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
}

void MovePlayer(Player* p, WINDOW* win) {
    do
    {
        curs_set(0);
        p->display();
        wrefresh(win);
    } while(p->getMove()!='q');
}




int main(int argc, char ** argv)
{
    initscr();

    int h, h1, h2, w, w1, w2, startY, startY1, startY2, startX, startX1, startX2;
    h = 25;
    h1 = h2 = 3;
    w = 90;
    w1 = w2 = 20;
    startY = startX = 5;
    startY1 = startY2 = 30;
    startX1 = 50;
    startX2 = 73;
    
    WINDOW * win = newwin(h, w, startY, startX);
    WINDOW * counter_window = newwin(h1, w1, startY1, startX1);
    WINDOW * points_window = newwin(h2, w2, startY2, startX2);
    refresh();

    box(win, 0, 0);
    mvwprintw(win, 24, 35, "Falling asteroids game");
    wrefresh(win);

    box(counter_window, 0, 0);
    mvwprintw(counter_window, 2, 8, "Time");
    wrefresh(counter_window);

    box(points_window, 0, 0);
    mvwprintw(points_window, 2, 7, "Points");
    wrefresh(points_window);

    Player * p =new Player(win, 15,15, '#');

    Engine * engine = new Engine(); 

    std::thread(MovePlayer, p, win);
    std::thread(GenerateStars, engine, win);
    std::thread(Counter, counter_window, points_window);

    int c = getch();

    endwin();

    return 0;
}