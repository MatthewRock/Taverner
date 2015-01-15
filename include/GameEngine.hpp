#ifndef GAMEENGINE_HPP
#define GAMEENGINE_HPP

#include "Initializer.hpp"

#include <vector> // For stack of states
#include <memory> // unique_ptr
#include "GameState.h"

/// \brief Main engine class.

//Private inheritance of Initializer ensures initialization of systems before game starts
namespace Taverner
{

    class GameEngine : private Initializer
    {
        public:
            GameEngine() = delete;//We need first state, otherwise starting engine doesn't make any sense.

            ~GameEngine() = default;
            void Update();
            void HandleEvents();
            void Draw();
            inline bool IsRunning() { return running; }
        private:
            bool running;
            void HandleEngineEvents();

            std::vector<std::unique_ptr<GameState> > states;
    };
}
#endif // GAMEENGINE_HPP
