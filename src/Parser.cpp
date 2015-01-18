#include "Parser.hpp"

#include "csout.hpp"

namespace Taverner
{
    std::string Parser::GetInput()
    {
        m_input = "";
        //Move to the last row, and to the end of string.
        csout.crMove(15 , 15);
        //Print console prompt
        csout << "> " << m_input;
        //Get input from getch to string
        //If input was enter, return command
        //If it wasn't, append to string and continue
        refresh();
        while(parseChar(getch()))
        {
            csout.crMove(0 , csout.MaxY() - 2);
            csout << "> " << m_input;
            refresh();
        }
        return m_input;

    }

    /** \brief Takes an action depending on input. Returns true if user hasn't pressed enter, false otherwise.
     *
     * \param x char <- input character from getch
     * \return bool <- false if x is enter. true otherwise.
     *
     */
    bool Parser::parseChar(char x)
    {
        //Parse text:
        switch(x)
        {
        //If it's enter
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
