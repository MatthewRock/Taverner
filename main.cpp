#include <iostream>
#include <ncursesw/curses.h>
#include <ncursesw/ncurses.h>
#include "csout.hpp"
using namespace std;

int main(int argc, char* argv[])
{
    initscr();
    Taverner::csout okienko;
    okienko << 5;
    refresh();
    getch();
    endwin();
    return 0;
}
