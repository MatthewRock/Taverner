#include "NPC.hpp"

#include "CommandWrite.hpp"

namespace Taverner
{

    NPC::NPC(std::string name, std::string desc, std::vector<std::pair<std::regex, std::string> > dialogues)
            : m_name(name), m_description(desc), m_dialogues(dialogues)
    {
        //Add default response for calling NPC's name ("hmm?") and for looking at it.
        std::string lookReg = ".*look";
        lookReg += R"((\s+.+\s+|\s+))";
        lookReg += name;
        lookReg += ".*";
        std::string nameReg = ".*" + name + ".*";
        m_dialogues.push_back(std::make_pair(std::regex(lookReg, std::regex_constants::ECMAScript | std::regex_constants::icase), m_description));
        //IMPORTANT! This is wildcard, it will match all previous commands, so it has to be last to make sure that it will be checked as last regex.
        m_dialogues.push_back(std::make_pair(std::regex(nameReg, std::regex_constants::ECMAScript | std::regex_constants::icase), "Hmm?"));
    }

    std::unique_ptr<Command> NPC::HandleEvents(std::string command)
    {
        //Loop for each line
        //First - regex, second - answer string
        for(auto& element : m_dialogues)
        {
            //If NPC has this line
            if(regex_match(command, element.first))
            {
                //Return command with proper line
                return std::unique_ptr<Command>(new CommandWrite(element.second, COLOR_MAGENTA));
            }
        }
        //Otherwise, nullptr is a sign that we didn't succeed
        return nullptr;
    }
}
