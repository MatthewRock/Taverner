#ifndef NPC_HPP
#define NPC_HPP

#include <string>
#include <vector>
#include <utility> //std::pair
#include <regex>

#include "Command.hpp"

namespace Taverner
{
    class NPC
    {
        public:
            NPC(std::string name, std::string desc, std::vector<std::pair<std::regex, std::string> > dialogues);
                //Checks if command can match regex. If yes, return command that will print output. Otherwise nullptr
                std::unique_ptr<Command> HandleEvents(std::string command);
                inline std::string GetName() { return m_name; }
                inline std::string GetDescription() { return m_description; }
        protected:
            std::string m_name;
            std::string m_description;
            //Dialogue regex - answer to that line.
            std::vector<std::pair<std::regex, std::string> > m_dialogues;
        private:

    };
}

#endif // NPC_HPP
