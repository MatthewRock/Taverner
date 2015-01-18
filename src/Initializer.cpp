#include "Initializer.hpp"

#include <ncursesw/ncurses.h>
#include "Logger.hpp"

namespace Taverner
{
    Initializer::Initializer()
    {
        initscr();
        //raw();
        //noecho();
        LOG_STRING("All systems initialized.");
    }

    Initializer::~Initializer()
    {
        endwin();
    }

}
