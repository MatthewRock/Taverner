//CSOUT - Console Stream Out.

#ifndef CSOUT_HPP
#define CSOUT_HPP

#include <ncursesw/ncurses.h>

namespace Taverner
{
    class csout
    {
        WINDOW* win;
    public:
        csout(WINDOW* w = stdscr) : win(w){};

        csout& operator<< (bool val);
        csout& operator<< (short val);
        csout& operator<< (unsigned short val);
        csout& operator<< (int val);
        csout& operator<< (unsigned int val);
        csout& operator<< (long val);
        csout& operator<< (unsigned long val);
        csout& operator<< (float val);
        csout& operator<< (double val);
        csout& operator<< (long double val);
    };
}

#endif // CSOUT_HPP

