#ifndef GAMEENGINE_HPP
#define GAMEENGINE_HPP

#include "Initializer.hpp"

/// \brief Main engine class.

//Private inheritance of Initializer ensures initialization of systems before game starts
namespace Taverner
{

    class GameEngine : private Initializer
    {
        public:
            GameEngine();
            ~GameEngine() = default;
            void Update() {};
            void HandleEvents() {};
            void Draw() {};
            inline bool IsRunning() { return running; }
        private:
            bool running;
            void HandleEngineEvents();
    };
}
#endif // GAMEENGINE_HPP
