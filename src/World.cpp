#include "World.hpp"

#include "Logger.hpp"
#include "CommandWrite.hpp"
#include "LocationParser.hpp"
#include "ItemParser.hpp"
#include "ItemsBank.h"
#include "CommandAddItem.hpp"
#include "GameEngine.hpp"
namespace Taverner
{
    World::World(Csout& csout)
    {
        AddRegex(R"(.*go(\s+.+\s+|\s+)north.*)",        COMMAND_PLAYER_GO_NORTH);
        AddRegex(R"(.*go(\s+.+\s+|\s+)south.*)",        COMMAND_PLAYER_GO_SOUTH);
        AddRegex(R"(.*go(\s+.+\s+|\s+)west.*)",         COMMAND_PLAYER_GO_WEST);
        AddRegex(R"(.*go(\s+.+\s+|\s+)east.*)",         COMMAND_PLAYER_GO_EAST);
        AddRegex(R"(.*my(\s+.+\s+|\s+)position.*)",     COMMAND_PLAYER_WRITE_POS);
        AddRegex(R"(.*my(\s+.+\s+|\s+)statistics.*)",   COMMAND_PLAYER_WRITE_STATS);
        AddRegex(R"(.*my(\s+.+\s+|\s+)items.*)",        COMMAND_PLAYER_WRITE_ITEMS);
        AddRegex(R"(equip.*)",                          COMMAND_PLAYER_EQUIP);
        LocationParser parser("world.xml");
        ItemParser parser2("world.xml");
        parser2.Parse();
        m_map = parser.Parse();
        //Print starting location's info
        m_map.find(std::make_pair(m_player.GetX(), m_player.GetY()))->second.PrintEverything(csout);
        CommandAddItem::SetPlayer(&m_player);
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
            //Find current x and y's location.
            auto place = m_map.find(std::make_pair(m_player.GetX(), m_player.GetY()));
            //If no location found(normally this shouldn't happen), do nothing.
            if(place != m_map.end())
                //Otherwise look for regex etc.
                m_command = place->second.HandleEvents(command);
            //If it was, m_command will not be nullptr, so we can stop searching
        }

        if(!m_command)
            HandleWorldCommands(resultCode, command);
    }
    void World::Update(GameEngine* eng)
    {
        if(m_player.Dead())
            eng->Quit();
        m_command->Execute();
        auto place = m_map.find(std::make_pair(m_player.GetX(), m_player.GetY()));
            //If player is not on board
        if(place == m_map.end())
            m_player.Hurt();
    }
    void World::Draw(Csout& csout)
    {
        m_command->Draw(csout);
        //If player has moved
        if(m_player.Moved())
        {
            //Unflag his move
            m_player.NoMove();
            //Look for his current location and print it.
            auto place = m_map.find(std::make_pair(m_player.GetX(), m_player.GetY()));
            //If player is at board
            if(place != m_map.end())
                place->second.PrintEverything(csout);
            else
            {
                csout << "The fog is so thick that you can't see anything. You hit the tree. You'd better go back to place where you can see something." << endl;
            }
        }
        if(m_player.Dead())
        {
            attron(COLOR_PAIR(COLOR_RED));
            csout << "You are dead. Type any command to leave the game in shame." << endl;
            attroff(COLOR_PAIR(COLOR_RED));
        }

    }
    void World::HandleWorldCommands(int code, std::string& command)
    {
        //Now we decide what command should be invoked.
        if(code < COMMAND_PLAYER_DELIMITER) // If it's command related to player
        {
            //Send player command.
            if(code == COMMAND_PLAYER_EQUIP)
                m_command = std::unique_ptr<Command>(new CommandPlayer(code, &m_player, command));
            else
                m_command = std::unique_ptr<Command>(new CommandPlayer(code, &m_player));
        }//... other commands
        else//If no command fits
        {
            //Send command to write error message. In red.
            m_command = std::unique_ptr<Command>(new CommandWrite("Command not recognized.", COLOR_RED));
        }
    }
}
