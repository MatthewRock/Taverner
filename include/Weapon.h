#ifndef WEAPON_H
#define WEAPON_H

#include "Item.h"

namespace Taverner
{
    class Weapon : public Item
    {
        public:
            Weapon(std::string name, std::string description, int value, unsigned dam, int def)
            : Item(name, description, value, ITEM_WEAPON), m_damage(dam), m_defence(def)
            {
            }
            ~Weapon() = default;

        protected:
            unsigned m_damage;
            int m_defence;
        private:
    };
}
#endif // WEAPON_H
