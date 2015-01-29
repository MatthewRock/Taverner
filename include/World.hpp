#ifndef WORLD_HPP
#define WORLD_HPP


/** \brief Aggregate class, that holds map and Player. Maybe even some "managers"
 */

#include <memory>
#include "Player.hpp"
#include "GameState.h"

#include <regex> // Regex for commands
#include <map>
#include <utility> // std::pair
#include "csout.hpp" // Printing
#include "Command.hpp" // Template for command Pattern classes
#include "Place.h"
#include "NPC.hpp"
#include "ItemsBank.h"

// TODO (s407267#1#): Add parsing items as separate parser

namespace Taverner
{
    //List of commands that can be used and sent in the World.
    enum WORLD_COMMANDS
    {
        COMMAND_PLAYER_GO_NORTH,
        COMMAND_PLAYER_GO_SOUTH,
        COMMAND_PLAYER_GO_WEST,
        COMMAND_PLAYER_GO_EAST,
        COMMAND_PLAYER_WRITE_STATS,
        COMMAND_PLAYER_WRITE_POS,
        COMMAND_PLAYER_WRITE_ITEMS,
        COMMAND_PLAYER_EQUIP,
        COMMAND_PLAYER_DELIMITER,
        COMMAND_UNKNOWN_COMMAND,
    };

    class World : public GameState
    {
        public:
            World(Csout& csout);
            void Pause();
            void Resume();
            void HandleEvents(std::string command);
            void Update(GameEngine* eng);
            void Draw(Csout& csout);

            inline void AddRegex(std::string text, int code)
            {
                //Add pair regex-code to vector. Regex is using ECMAScript dialect and is case insensitive.
                m_commands.push_back(std::make_pair(std::regex(text, std::regex_constants::ECMAScript | std::regex_constants::icase), code));
            }
        protected:
        private:
            std::unique_ptr<Command> m_command;
            std::vector<std::pair<std::regex, int> > m_commands;

            Player m_player;
            // This vector will simulate 2D-array that will be extensible.
            std::map<std::pair<int, int>, Place> m_map;

            void HandleWorldCommands(int code, std::string& str);
            void InitializeMap(std::string pathname);
    };

    /**< Below: Commands implementations */

    //Class that allows us to invoke commands that relate to player.
    class CommandPlayer : public Command
    {
        int m_code;
        Player* m_player;
        std::string m_item;
        bool success;
        public:
            CommandPlayer(int code, Player* player, std::string item = "") : m_code(code), m_player(player), m_item(item), success(true) {}
            void Draw(Csout& csout)
            {
                attron(COLOR_PAIR(COLOR_YELLOW));
                switch(m_code)
                {
                case COMMAND_PLAYER_WRITE_POS:
                    csout << "My position: " << m_player->GetX() << " " << m_player->GetY() << endl;
                    break;
                case COMMAND_PLAYER_WRITE_ITEMS:
                    m_player->PrintItems(csout);
                    break;
                case COMMAND_PLAYER_WRITE_STATS:
                    m_player->PrintStats(csout);
                    break;
                default:
                    if(success)
                        csout << "OK" << endl;
                    else
                    {
                        attroff(COLOR_PAIR(COLOR_YELLOW));
                        attron(COLOR_PAIR(COLOR_RED));
                        csout << "Sorry, can't do this." << endl;
                        attroff(COLOR_PAIR(COLOR_RED));
                        attron(COLOR_PAIR(COLOR_YELLOW));
                    }
                    break;
                }
                attroff(COLOR_PAIR(COLOR_YELLOW));
            }
            void Execute()
            {
                switch(m_code)
                {
                    //By default, print error message
                case COMMAND_PLAYER_GO_EAST:
                    m_player->Move(1, 0);
                    break;
                case COMMAND_PLAYER_GO_NORTH:
                    m_player->Move(0, 1);
                    break;
                case COMMAND_PLAYER_GO_SOUTH:
                    m_player->Move(0, -1);
                    break;
                case COMMAND_PLAYER_GO_WEST:
                    m_player->Move(-1, 0);
                    break;
                case COMMAND_PLAYER_EQUIP:
                    success = m_player->Equip(m_item);
                    break;
                default:
                    break;
                }
            }
    };


}
#endif // WORLD_HPP
