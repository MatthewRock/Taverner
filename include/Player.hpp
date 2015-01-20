#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <Creature.h>

namespace Taverner
{
    class Player : public Creature
    {
        public:
            Player() = default;
            void Move(int x, int y);
            inline int GetX() { return m_x; }
            inline int GetY() { return m_y; }

            ~Player() = default;
        protected:
        private:
            int m_x, m_y;
    };
}
#endif // PLAYER_HPP

//Scheme:
//Create World that will hold Player and Map.
//World handles player input by checking if he can move in Map.
//For now, moving suffices
