#ifndef ARMOUR_H
#define ARMOUR_H

#include "Item.h"

namespace Taverner
{
    class Armour : public Item
    {
        public:
            enum Slot {Torso, Head, Shield, Legs, N};
            Armour(std::string name, std::string description, int val, unsigned def, Armour::Slot slot)
            : Item(name, description, val, ITEM_ARMOUR), m_defence(def), m_slot(slot)
            {}

            ~Armour() = default;
        protected:
            unsigned m_defence;
            Slot m_slot;
        private:
    };
}
#endif // ARMOUR_H
