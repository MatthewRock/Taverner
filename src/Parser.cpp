#include "Parser.hpp"

#include "csout.hpp"

namespace Taverner
{
    std::string Parser::GetInput(Csout& csout)
    {
        m_input = "";
        //Move to the last row, and to the end of string.
        csout.CrMove(0 , csout.MaxY() - 1);
        //Print console prompt and clear line
        csout << "> ";
        clrtoeol();
        //Print everything to screen
        csout.Refresh();
        //Start getting input with parseChar, until enter is encountered
        while(parseChar(csout.Getch()))
        {
            //After each char entered, move to the beginning of the line
            csout.CrMove(0 , csout.MaxY() - 1);
            //Print console prompt with input string
            csout << "> " << m_input;
            //And clear the rest of line
            clrtoeol();
            //After that, print everything to screen.
            csout.Refresh();
        }
        return m_input;

    }

    /** \brief Takes an action depending on input. Returns true if user hasn't pressed enter, false otherwise.
     *
     * \param x char <- input character from getch
     * \return bool <- false if x is enter. true otherwise.
     *
     */
    bool Parser::parseChar(int x)
    {
        //Parse text:
        switch(x)
        {
        //If it's enter(on win/linux)
        case '\n':
        case '\r':
        case KEY_ENTER:
            //Return false
            return false;
            break;
            //If key is backspace
        case KEY_BACKSPACE:
            //If input isn't already empty
            if(!m_input.empty())
            {
                //Remove last letter
                m_input.pop_back();
            }
            //Else don't do anything
            break;
            //By default just add the pressed key to input.
        default:
            m_input += x;
        }
        return true;
    }
}
