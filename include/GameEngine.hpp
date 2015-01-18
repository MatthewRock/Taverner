#ifndef GAMEENGINE_HPP
#define GAMEENGINE_HPP

#include "Initializer.hpp"

#include <vector> // For stack of states
#include <memory> // unique_ptr
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

        private:
            void Update();
            void HandleEngineEvents(std::string ch);
            void HandleEvents();
            void Draw();

            inline void Quit() { m_running = false; }
            inline bool IsRunning() { return m_running; }

            std::vector<std::unique_ptr<GameState> > m_states;
            bool m_running;
            Parser m_parser;
            Csout m_csout;
    };
}
#endif // GAMEENGINE_HPP
