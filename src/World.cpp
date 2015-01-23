#include "World.hpp"

#include "Logger.hpp"
namespace Taverner
{
    World::World()
    {
        AddRegex(R"(.*go(\s+.+\s+|\s+)north.*)", COMMAND_GO_NORTH);
        AddRegex(R"(.*go(\s+.+\s+|\s+)south.*)", COMMAND_GO_SOUTH);
        AddRegex(R"(.*go(\s+.+\s+|\s+)west.*)", COMMAND_GO_WEST);
        AddRegex(R"(.*go(\s+.+\s+|\s+)east.*)", COMMAND_GO_EAST);
    }
    void World::Pause()
    {
        GameState::Pause();
    }
    void World::Resume()
    {
        GameState::Resume();
    }
    void World::HandleEvents(std::string command)
    {
        //Assign default "error" message
        int resultCode = COMMAND_N;
        //Check if any regex is found
        for(auto& element : m_commands)
        {
            //If yes, get its code, and exit loop
            if(regex_match(command, element.first))
            {
                resultCode = element.second;
                break;
            }
        }
        HandleWorldCommands(resultCode, command);
    }
    void World::Update(GameEngine* eng)
    {
        m_command->Execute();
    }
    void World::Draw(Csout& csout)
    {
        m_command->Draw(csout);
    }
    void World::HandleWorldCommands(int code, std::string& command)
    {
        //Now we decide what command should be invoked.
        switch(code)
        {
            //If we want to move, get CommandGo to work.
        case COMMAND_GO_EAST:
        case COMMAND_GO_NORTH:
        case COMMAND_GO_SOUTH:
        case COMMAND_GO_WEST:
            m_command = std::unique_ptr<Command>(new CommandGo(code, &m_player));
            break;
        //If there's no command or some bug happened, print error message
        case COMMAND_N:
        default:
            m_command = std::unique_ptr<Command>(new CommandWrite("Command not recognized.", 1));
            break;
        }
    }
}
