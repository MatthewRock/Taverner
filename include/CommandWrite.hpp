#ifndef COMMANDWRITE_HPP
#define COMMANDWRITE_HPP

#include <string>
#include "csout.hpp"

namespace Taverner
{
    class CommandWrite : public Command
    {
        std::string m_msg;
        int m_color;
        public:
            CommandWrite(std::string message, int col = -1) : m_msg(message), m_color(col) {}
            void Draw(Csout& csout)
            {
                if(m_color != -1)
                {
                    attron(COLOR_PAIR(m_color));
                    csout << m_msg << endl;
                    attroff(COLOR_PAIR(m_color));
                }
                else
                    csout << m_msg << endl;

            }
            void Execute() {}
    };
}
#endif // COMMANDWRITE_HPP
