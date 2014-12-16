#include "csout.hpp"

using namespace Taverner;

csout& operator<< (const csout& stream, bool val)
{
    wprintw(stream.win, "%d", val);
}

csout& operator<< (const csout& stream, short val)
{
    wprintw(win, "%d", val);
}

csout& operator<< (const csout& stream, unsigned short val)
{
    wprintw(win, "%u", val);
}

csout& operator<< (const csout& stream, int val)
{
    wprintw(win, "%d", val);
}

csout& operator<< (const csout& stream, unsigned int val)
{
    wprintw(win, "%u", val);
}

csout& operator<< (const csout& stream, long val)
{
    wprintw(win, "%d", val);
}

csout& operator<< (const csout& stream, unsigned long val)
{
    wprintw(win, "%u", val);
}

csout& operator<< (const csout& stream, float val)
{
    wprintw(win, "%f", val);
}

csout& operator<< (const csout& stream, double val)
{
    wprintw(win, "%f", val);
}

csout& operator<< (const csout& stream, long double val)
{
    wprintw(win, "%f", val);
}

csout& operator<< (const csout& stream, char val)
{
    wprintw(win, "%c", val);
}

csout& operator<< (const csout& stream, const char* val)
{
    wprintw(win, "%s", val);
    return stream;
}
