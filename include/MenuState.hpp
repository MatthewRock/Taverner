#ifndef MENUSTATE_HPP
#define MENUSTATE_HPP

#include "GameState.h"

#include <string>
#include <vector>
#include "World.hpp"

namespace Taverner
{
    class MenuState : public GameState
    {
        public:
            //Creates menu with greet as top text, and options as menu positions.
            MenuState(Csout& csout);
            ~MenuState() = default;

            void Pause();
            void Resume();
            void HandleEvents(std::string command);
            void Update(GameEngine* eng);
            void Draw(Csout& csout);

        protected:
        private:
            std::string m_greet;
            std::vector<std::string> m_options;
            unsigned userInput;
    };
}
#endif // MENUSTATE_HPP
