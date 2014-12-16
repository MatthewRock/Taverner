#include "csout.hpp"

using namespace Taverner;

csout& csout::operator<< (bool val)
{

}

csout& csout::operator<< (short val)
{

}

csout& csout::operator<< (unsigned short val)
{

}

csout& csout::operator<< (int val)
{
    wprintw(win, "%d", val);
}

csout& csout::operator<< (unsigned int val)
{

}

csout& csout::operator<< (long val)
{

}

csout& csout::operator<< (unsigned long val)
{

}

csout& csout::operator<< (float val)
{

}

csout& csout::operator<< (double val)
{

}

csout& csout::operator<< (long double val)
{

}

