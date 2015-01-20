#include "World.hpp"

namespace Taverner
{
    World::World() : m_player(new Player())
    {
        AddRegex( R"(.*go(\s+.+\s+|\s+)north.*)", COMMAND_GO_NORTH);
        AddRegex( R"(.*go(\s+.+\s+|\s+)south.*)", COMMAND_GO_SOUTH);
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
        int resultCode = COMMAND_N;
        for(auto& element : m_commands)
        {
            if(regex_match(command, element.first))
            {
                resultCode = element.second;
                break;
            }
        }
// TODO (malice#1#): Wonder about how to actually handle events, so that Update and Draw can have an idea about what to do without passing command around.


    }
    void World::Update(GameEngine* eng)
    {

    }
    void World::Draw(Csout& csout)
    {

    }
    void HandleWorldCommands(int code)
    {
        switch(code)
        {
            //By default, print error message
        case COMMAND_N:
        default:

        }
    }
}
