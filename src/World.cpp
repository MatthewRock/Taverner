#include "World.hpp"

#include "Logger.hpp"
namespace Taverner
{
    World::World(Csout& printer) : m_csout(printer)
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
        //Translate command into code
        LOG_STRING("In HandleEvents");
        LOG_STRING(command.c_str());
        int resultCode = COMMAND_N;
        for(auto& element : m_commands)
        {
            if(regex_match(command, element.first))
            {
                resultCode = element.second;
                break;
            }
        }
        std::string str = "Result code:" + resultCode;
        LOG_STRING(str);
        //HandleWorldCommands(resultCode);
        m_command = std::unique_ptr<Command>(new CommandGo(resultCode, m_csout, &m_player));
// TODO (malice#1#): Wonder about how to actually handle events, so that Update and Draw can have an idea about what to do without passing command around.


    }
    void World::Update(GameEngine* eng)
    {
        m_command->Execute();
    }
    void World::Draw(Csout& csout)
    {

    }
    void World::HandleWorldCommands(int code)
    {
        switch(code)
        {
            //By default, print error message
        case COMMAND_GO_EAST:
        case COMMAND_GO_NORTH:
        case COMMAND_GO_SOUTH:
        case COMMAND_GO_WEST:
            m_csout << "Regex matched in World!" << endl;
            break;
        case COMMAND_N:
        default:
            break;
        }
    }
}
