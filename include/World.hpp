#ifndef WORLD_HPP
#define WORLD_HPP


/** \brief Aggregate class, that holds map and Player. Maybe even some "managers"
 */

#include <memory>
#include "Player.hpp"
#include "GameState.h"

#include <regex> // Regex for commands
#include <utility> // std::pair
#include "csout.hpp" // Printing
#include "Command.hpp" // Template for command Pattern classes
#include "Place.h"

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
        COMMAND_PLAYER_DELIMITER,
        COMMAND_UNKNOWN_COMMAND,
    };

    class World : public GameState
    {
        public:
            World();
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
            void HandleWorldCommands(int code, std::string& str);
            std::vector<std::pair<std::regex, int> > m_commands;

            void InitializeMap(std::string pathname);

            std::unique_ptr<Command> m_command;
            Player m_player;

            // This vector will simulate 2D-array that will be extensible.
            std::vector<Place> m_map;
            unsigned m_mapX;
            inline Place& GetLocation(int x, int y)
            {
                return m_map[x + y * m_mapX];
            }
    };



    /**< Below: Commands implementations */


    //Class that allows us to invoke commands that relate to player.
    class CommandPlayer : public Command
    {
        int m_code;
        Player* m_player;
        public:
            CommandGo(int code, Player* player) : m_code(code), m_player(player) {}
            void Draw(Csout& csout)
            {
                attron(COLOR_PAIR(COLOR_BLUE));
                switch(m_code)
                {
                case COMMAND_PLAYER_WRITE_POS:
                    csout << "Player position: " << m_player->GetX() << " " << m_player->GetY() << endl;
                    break;
                case COMMAND_PLAYER_WRITE_STATS:
                    csout << "Write player stats." << endl;
                    break;
                default:
                    csout << "OK" << endl;
                    break;
                }
                attron(COLOR_PAIR(COLOR_BLUE));
            }
            void Execute()
            {
                switch(m_code)
                {
                    //By default, print error message
                case COMMAND_GO_EAST:
                    m_player->Move(1, 0);
                    break;
                case COMMAND_GO_NORTH:
                    m_player->Move(0, 1);
                    break;
                case COMMAND_GO_SOUTH:
                    m_player->Move(0, -1);
                    break;
                case COMMAND_GO_WEST:
                    m_player->Move(-1, 0);
                    break;
                default:
                    break;
                }
            }
    };
    class CommandWrite : public Command
    {
        std::string m_msg;
        int m_color;
        public:
            CommandWrite(std::string message, int col = -1) : m_msg(message), m_color(col) {}
            void Draw(Csout& csout)
            {
                if(m_color != -1)
                {
                    attron(COLOR_PAIR(m_color));
                    csout << m_msg << endl;
                    attroff(COLOR_PAIR(m_color));
                }
                else
                    csout << m_msg << endl;

            }
            void Execute() {}
    };

}
#endif // WORLD_HPP
