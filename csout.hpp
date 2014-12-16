//CSOUT - Console Stream Out.

#ifndef CSOUT_HPP
#define CSOUT_HPP

#include <ncursesw/ncurses.h>

namespace Taverner
{
    class csout
    {
        WINDOW* win;
        int x;
    public:
        csout(WINDOW* w = stdscr) : win(w){};
        csout(const csout& x) = default;

        ~csout() = default;
        friend void hello(csout& obj);
        friend csout& operator<< (csout& stream, bool val);
        friend csout& operator<< (csout& stream, short val);
        friend csout& operator<< (csout& stream, unsigned short val);
        friend csout& operator<< (csout& stream, int val);
        friend csout& operator<< (csout& stream, unsigned int val);
        friend csout& operator<< (csout& stream, long val);
        friend csout& operator<< (csout& stream, unsigned long val);
        friend csout& operator<< (csout& stream, float val);
        friend csout& operator<< (csout& stream, double val);
        friend csout& operator<< (csout& stream, long double val);
        friend csout& operator<< (csout& stream, char val);
        friend csout& operator<< (csout& stream, const char* val);
    };
}

#endif // CSOUT_HPP

