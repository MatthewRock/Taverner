#include "csout.hpp"

namespace Taverner
{
    Csout& operator<< (Csout& stream, bool val)
    {
        wprintw(stream.win, "%d", val);
        refresh();
        return stream;
    }

    Csout& operator<< (Csout& stream, short val)
    {
        wprintw(stream.win, "%d", val);
        refresh();
        return stream;
    }

    Csout& operator<< (Csout& stream, unsigned short val)
    {
        wprintw(stream.win, "%u", val);
        refresh();
        return stream;
    }

    Csout& operator<< (Csout& stream, int val)
    {
        wprintw(stream.win, "%d", val);
        refresh();
        return stream;
    }

    Csout& operator<< (Csout& stream, unsigned int val)
    {
        wprintw(stream.win, "%u", val);
        refresh();
        return stream;
    }

    Csout& operator<< (Csout& stream, long val)
    {
        wprintw(stream.win, "%d", val);
        refresh();
        return stream;
    }

    Csout& operator<< (Csout& stream, unsigned long val)
    {
        wprintw(stream.win, "%u", val);
        refresh();
        return stream;
    }

    Csout& operator<< (Csout& stream, float val)
    {
        wprintw(stream.win, "%f", val);
        refresh();
        return stream;
    }

    Csout& operator<< (Csout& stream, double val)
    {
        wprintw(stream.win, "%f", val);
        refresh();
        return stream;
    }

    Csout& operator<< (Csout& stream, long double val)
    {
        wprintw(stream.win, "%f", val);
        refresh();
        return stream;
    }

    Csout& operator<< (Csout& stream, char val)
    {
        wprintw(stream.win, "%c", val);
        refresh();
        return stream;
    }

    Csout& operator<< (Csout& stream, const char* val)
    {
        wprintw(stream.win, "%s", val);
        refresh();
        return stream;
    }
    Csout& operator<< (Csout& stream, std::string val)
    {
        wprintw(stream.win, "%s", val.c_str());
        refresh();
        return stream;
    }
    void Csout::crMove(int x, int y)
    {
        wmove(win, y, x);
    }

    char endl = '\n';
}
