//CSOUT - Console Stream Out.

#ifndef CSOUT_HPP
#define CSOUT_HPP

#include <ncursesw/ncurses.h>
#include <string>

namespace Taverner
{
    class Csout
    {
        WINDOW* win;
        int maxX, maxY;
    public:
        Csout(WINDOW* w = stdscr) : win(w)
        {
            getmaxyx(win, maxY, maxX);
        };
        Csout(const Csout& x) = default;

        ~Csout() = default;

        friend Csout& operator<< (Csout& stream, bool val);
        friend Csout& operator<< (Csout& stream, short val);
        friend Csout& operator<< (Csout& stream, unsigned short val);
        friend Csout& operator<< (Csout& stream, int val);
        friend Csout& operator<< (Csout& stream, unsigned int val);
        friend Csout& operator<< (Csout& stream, long val);
        friend Csout& operator<< (Csout& stream, unsigned long val);
        friend Csout& operator<< (Csout& stream, float val);
        friend Csout& operator<< (Csout& stream, double val);
        friend Csout& operator<< (Csout& stream, long double val);
        friend Csout& operator<< (Csout& stream, char val);
        friend Csout& operator<< (Csout& stream, const char* val);
        friend Csout& operator<< (Csout& stream, std::string val);

        void crMove(int x, int y);
        inline void refresh() { wrefresh(win); }
        inline int MaxX() { return maxX; }
        inline int MaxY() { return maxY; }
    };

    extern char endl;
    extern Csout csout;
}

#endif // CSOUT_HPP

