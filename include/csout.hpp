//CSOUT - Console Stream Out.

#ifndef CSOUT_HPP
#define CSOUT_HPP

#include <ncursesw/ncurses.h>
#include <string>
#include "Logger.hpp"

namespace Taverner
{
    class Csout
    {
        WINDOW* m_win;
        int m_maxX, m_maxY;
    public:
        Csout(WINDOW* w = stdscr)
        {
            initscr();
            m_win = w;
            getmaxyx(m_win, m_maxY, m_maxX);
            //Create colors to use in later occurances.
            init_pair(COLOR_RED, COLOR_RED, COLOR_BLACK);
            init_pair(COLOR_GREEN, COLOR_GREEN, COLOR_BLACK);
            init_pair(COLOR_YELLOW, COLOR_YELLOW, COLOR_BLACK);
            init_pair(COLOR_BLUE, COLOR_BLUE, COLOR_BLACK);
            init_pair(COLOR_MAGENTA, COLOR_MAGENTA, COLOR_BLACK);
            init_pair(COLOR_CYAN, COLOR_WHITE, COLOR_BLACK);
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

        inline int Getch()
        {
            return wgetch(m_win);
        }

        void CrMove(int x, int y);
        inline void Refresh() { wrefresh(m_win); }
        inline int MaxX() { return m_maxX; }
        inline int MaxY() { return m_maxY; }
    };

    extern char endl;
   // extern Csout csout;
}

#endif // CSOUT_HPP

