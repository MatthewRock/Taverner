#ifndef ARMOUR_H
#define ARMOUR_H

#include "Item.h"

namespace Taverner
{
    enum SLOT {SLOT_TORSO, SLOT_HEAD, SLOT_SHIELD, SLOT_LEGS, SLOT_N};
    class Armour : public Item
    {
        public:
            Armour(std::string name, std::string description, int val, unsigned def, int slot)
            : Item(name, description, val, ITEM_ARMOUR), m_defence(def), m_slot(slot)
            {}

            ~Armour() = default;
            inline unsigned GetDef() { return m_defence; }
            inline int GetSlot() { return m_slot; }
        protected:
            unsigned m_defence;
            int m_slot;
        private:
    };
}
#endif // ARMOUR_H
