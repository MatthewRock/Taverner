#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <Creature.h>
#include <vector>
#include <utility>//std::pair
namespace Taverner
{
    class Player : public Creature
    {
        public:
            Player();
            void Move(int x, int y);
            inline int GetX() { return m_x; }
            inline int GetY() { return m_y; }

            ~Player() = default;
            inline bool Moved() { return m_moved; }
            inline void NoMove() { m_moved = false; }

            void AddItem(int code, int quantity);
            void RemoveItem(int code, int quantity);
// TODO (s407267#1#): Finish implementing items: player can have eq, equip items, look at eq and stats. ...
//THEN: //3

        protected:
        private:
            int m_x, m_y;
// TODO (s407267#1#): Implement attack and stats
            int m_atk, m_def;
            bool m_moved;
            //Pair item - quantity
            std::vector<std::pair<int, int> > m_equipement;

    };
}
#endif // PLAYER_HPP

//Scheme:
//Create World that will hold Player and Map.
//World handles player input by checking if he can move in Map.
//For now, moving suffices
