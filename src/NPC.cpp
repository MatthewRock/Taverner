#include "NPC.hpp"

#include "CommandWrite.hpp"

namespace Taverner
{
    std::unique_ptr<Command> NPC::HandleEvents(std::string command)
    {
        //Loop for each line
        //First - regex, second - answer string
        for(auto& element : m_commands)
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
