#ifndef WORLD_HPP
#define WORLD_HPP


/** \brief Aggregate class, that holds map and Player. Maybe even some "managers"
 */

#include <memory>
#include "Player.hpp"
#include "GameState.h"

#include <regex> // Regex for commands
#include <utility> // std::pair
#include "csout.hpp"
#include "Command.hpp"

namespace Taverner
{
    enum WORLD_COMMANDS
    {
        COMMAND_GO_NORTH,
        COMMAND_GO_SOUTH,
        COMMAND_GO_WEST,
        COMMAND_GO_EAST,
        COMMAND_N,
    };
    class World : public GameState
    {
        public:
            World(Csout& printer);
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
            void HandleWorldCommands(int code);
            std::vector<std::pair<std::regex, int> > m_commands;

            //The code that received command will be translated to
            WORLD_COMMANDS resultCode;
            Csout& m_csout;
            std::unique_ptr<Command> m_command;
            Player m_player;
    };

    class CommandGo : public Command
    {
        int m_code;
        Csout& m_csout;
        Player* m_player;
        public:
            CommandGo(int code, Csout& csout, Player* player) : m_code(code), m_csout(csout), m_player(player) {}
            void Draw() {}
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
                case COMMAND_N:
                default:
                    break;
                }
                    m_csout << "Player position: " << m_player->GetX() << " " << m_player->GetY() << endl;
            }
    };
}
#endif // WORLD_HPP
