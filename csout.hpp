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
        csout(const csout& x) = default;

        ~csout() = default;

        friend csout& operator<< (const csout& stream, bool val);
        friend csout& operator<< (const csout& stream, short val);
        friend csout& operator<< (const csout& stream, unsigned short val);
        friend csout& operator<< (const csout& stream, int val);
        friend csout& operator<< (const csout& stream, unsigned int val);
        friend csout& operator<< (const csout& stream, long val);
        friend csout& operator<< (const csout& stream, unsigned long val);
        friend csout& operator<< (const csout& stream, float val);
        friend csout& operator<< (const csout& stream, double val);
        friend csout& operator<< (const csout& stream, long double val);
        friend csout& operator<< (const csout& stream, char val);
        friend csout& operator<< (const csout& stream, const char* val);
    };
}

#endif // CSOUT_HPP

