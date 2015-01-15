#ifndef MENUSTATE_HPP
#define MENUSTATE_HPP

#include "GameState.h"

namespace Taverner
{

    class MenuState : public GameState
    {
        public:
            MenuState();
            MenuState(const MenuState& other);
            MenuState(MenuState&&);
            MenuState& operator=(const MenuState& other);
            MenuState& operator=(MenuState&&);
            ~MenuState();
            void Pause();
            void Resume();
            void HandleEvents();
            void Update();
            void Draw();
            void ChangeState();

        protected:
        private:
    };
}
#endif // MENUSTATE_HPP
