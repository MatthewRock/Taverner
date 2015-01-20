#ifndef WORLD_HPP
#define WORLD_HPP


/** \brief Aggregate class, that holds map and Player. Maybe even some "managers"
 */

#include <memory>
#include "Player.hpp"
#include "GameState.h"

#include <regex> // Regex for commands
#include <utility> // std::pair

namespace Taverner
{
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
            void HandleWorldCommands(int code);
            std::unique_ptr<Player> m_player;
            std::vector<std::pair<std::regex, int> > m_commands;
            enum WORLD_COMMANDS
            {
                COMMAND_GO_NORTH,
                COMMAND_GO_SOUTH,
                COMMAND_GO_WEST,
                COMMAND_GO_EAST,
                COMMAND_N,
            };
            //The code that received command will be translated to
            WORLD_COMMANDS resultCode;
    };
}
#endif // WORLD_HPP
