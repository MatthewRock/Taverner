#include "Parser.hpp"

#include "csout.hpp"

namespace Taverner
{
    std::string Parser::GetInput()
    {
        //Move to the last row
        csout.crMove(0, csout.MaxY() - 1);
        //Print console prompt
        csout << "> " << m_input;
        //Get input from getch to string
        //If input was enter, return command
        //If it wasn't, append to string and continue

    }
}
