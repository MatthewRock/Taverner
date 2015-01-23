#include "Initializer.hpp"

#include <ncursesw/ncurses.h>
#include "Logger.hpp"

namespace Taverner
{
    Initializer::Initializer()
    {
        //Initialize curses screen
        initscr();
        //Mode: grab input as soon as it gets there, don't wait for enter/space.
        raw();
        //Mode: don't display(echo) input to console.
        noecho();
        //Mode: allow using additional keys(F1, Enter, Tab, etc.) in stdscr.
        keypad(stdscr, TRUE);
        //Allow using different colors
        if(has_colors() == FALSE)
            throw -1;
        start_color();
        LOG_STRING("All systems initialized.");
    }

    Initializer::~Initializer()
    {
        //Close curses window.
        endwin();
    }

}
