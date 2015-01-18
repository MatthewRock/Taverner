#ifndef PARSER_HPP
#define PARSER_HPP

#include <string>

namespace Taverner
{
    class Parser
    {
        std::string m_input;
        bool parseChar(char x);
        public:
        std::string GetInput();
    };
}

#endif // PARSER_HPP

