#include <ncurses.h>
#include <unistd.h>
using namespace std;

int main(int argc, char ** argv) {
  initscr();
  refresh();
  for(int i=0; i < 10; i++) {
    mvprintw(i, i, "*");
    refresh();
    sleep(1);
    mvdelch(i, i);
  }
  mvprintw(20, 20, "Hello");
  getch();
  endwin();
  return 0;
}
