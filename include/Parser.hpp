#ifndef PARSER_HPP
#define PARSER_HPP

#include <string>

namespace Taverner
{
    class Csout;
    class Parser
    {
        std::string m_input;
        bool parseChar(int x);
        public:
        std::string GetInput(Csout& csout);
    };
}

#endif // PARSER_HPP

