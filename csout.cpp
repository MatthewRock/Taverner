#include "csout.hpp"

namespace Taverner
{

    csout& operator<< (csout& stream, bool val)
    {
        wprintw(stream.win, "%d", val);
        return stream;
    }

    csout& operator<< (csout& stream, short val)
    {
        wprintw(stream.win, "%d", val);
        return stream;
    }

    csout& operator<< (csout& stream, unsigned short val)
    {
        wprintw(stream.win, "%u", val);
        return stream;
    }

    csout& operator<< (csout& stream, int val)
    {
        wprintw(stream.win, "%d", val);
        return stream;
    }

    csout& operator<< (csout& stream, unsigned int val)
    {
        wprintw(stream.win, "%u", val);
        return stream;
    }

    csout& operator<< (csout& stream, long val)
    {
        wprintw(stream.win, "%d", val);
        return stream;
    }

    csout& operator<< (csout& stream, unsigned long val)
    {
        wprintw(stream.win, "%u", val);
        return stream;
    }

    csout& operator<< (csout& stream, float val)
    {
        wprintw(stream.win, "%f", val);
        return stream;
    }

    csout& operator<< (csout& stream, double val)
    {
        wprintw(stream.win, "%f", val);
        return stream;
    }

    csout& operator<< (csout& stream, long double val)
    {
        wprintw(stream.win, "%f", val);
        return stream;
    }

    csout& operator<< (csout& stream, char val)
    {
        wprintw(stream.win, "%c", val);
        return stream;
    }

    csout& operator<< (csout& stream, const char* val)
    {
        wprintw(stream.win, "%s", val);
        return stream;
    }

}
