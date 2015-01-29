#ifndef GAMEENGINE_HPP
#define GAMEENGINE_HPP

#include "Initializer.hpp"

#include <vector> // For stack of states
#include <memory> // unique_ptr
#include <regex> // For commands(regex)
#include "GameState.h"

/// \brief Main engine class.
#include "csout.hpp"
#include "Parser.hpp"

//Private inheritance of Initializer ensures initialization of systems before game starts
namespace Taverner
{
    class GameEngine : private Initializer
    {
        public:
            GameEngine();
            ~GameEngine() = default;

            inline void Run()
            {
                while(IsRunning())
                {
                    HandleEvents();
                    Update();
                    Draw();
                }
            }

            void ChangeState(GameState* state);
            void PushState(GameState* state);
            void PopState();
            inline void Quit() { m_running = false; }

        private:
            void Update();
            void HandleEngineEvents(std::string ch);
            void HandleEvents();
            void Draw();
            inline void AddRegex(std::string text, int code)
            {
                //Add pair regex-code to vector. Regex is using ECMAScript dialect and is case insensitive.
                m_commands.push_back(std::make_pair(std::regex(text, std::regex_constants::ECMAScript | std::regex_constants::icase), code));
            }

            inline bool IsRunning() { return m_running; }

            std::vector<std::unique_ptr<GameState> > m_states;
            bool m_running;
            Parser m_parser;
            Csout m_csout;
            //A vector of pairs: regex, and code (enum) for matching option.
            std::vector<std::pair<std::regex, int> > m_commands;
            enum ENGINE_COMMANDS
            {
                COMMAND_EXIT,
                COMMAND_N,
            };
    };
}
#endif // GAMEENGINE_HPP
