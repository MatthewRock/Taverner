#include "Initializer.hpp"

#include <ncursesw/ncurses.h>
#include "Logger.hpp"

namespace Taverner
{
    Initializer::Initializer()
    {
        initscr();
        LOG_STRING("All systems initialized.");
    }

    Initializer::~Initializer()
    {
        endwin();
    }

}