#include <iostream>
#include "csout.hpp"
using namespace std;

int main(int argc, char* argv[])
{
    int x = 5;
    initscr();
    Taverner::csout okienko;
    //wprintw(stdscr, "Hello, world!");
    okienko << "Hello, world!" << "test";//'\n'; //<< "This number: " << x << " is equal to five!";
    refresh();
    getch();
    endwin();
    return 0;
}
