#include "World.hpp"

#include "Logger.hpp"
#include "CommandWrite.hpp"
#include "LocationParser.hpp"

namespace Taverner
{
    World::World()
    {
        AddRegex(R"(.*go(\s+.+\s+|\s+)north.*)",        COMMAND_PLAYER_GO_NORTH);
        AddRegex(R"(.*go(\s+.+\s+|\s+)south.*)",        COMMAND_PLAYER_GO_SOUTH);
        AddRegex(R"(.*go(\s+.+\s+|\s+)west.*)",         COMMAND_PLAYER_GO_WEST);
        AddRegex(R"(.*go(\s+.+\s+|\s+)east.*)",         COMMAND_PLAYER_GO_EAST);
        AddRegex(R"(.*my(\s+.+\s+|\s+)position.*)",     COMMAND_PLAYER_WRITE_POS);
        AddRegex(R"(.*my(\s+.+\s+|\s+)statistics.*)",   COMMAND_PLAYER_WRITE_STATS);
        LocationParser parser("world.xml");
// TODO (s407267#1#): Format correctly somethingsomething
//Vector acces violation: corrupted memory accessed. Fix it.
        unsigned mapY;
        m_map = parser.Parse();
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
        int resultCode = COMMAND_UNKNOWN_COMMAND;
        m_command = nullptr;
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
        //If no regex was found, continue searching:
        if(resultCode == COMMAND_UNKNOWN_COMMAND)
        {

            //Each NPC will check if this is his line
            m_command = m_map.find(std::make_pair(m_player.GetX(), m_player.GetY()))->second.HandleEvents(command);
            //If it was, m_command will not be nullptr, so we can stop searching
// TODO (s407267#1#): NPC Not found

        }

        if(!m_command)
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
        if(code < COMMAND_PLAYER_DELIMITER) // If it's command related to player
        {
            //Send player command.
            m_command = std::unique_ptr<Command>(new CommandPlayer(code, &m_player));
        }//... other commands
        else//If no command fits
        {
            //Send command to write error message. In red.
            m_command = std::unique_ptr<Command>(new CommandWrite("Command not recognized.", COLOR_RED));
        }
    }
}
