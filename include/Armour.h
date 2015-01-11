#ifndef ARMOUR_H
#define ARMOUR_H

#include "Item.h"

namespace Taverner
{
    class Armour : public Item
    {
        public:
            enum Slot {Torso, Head, Legs, N};
            Armour() = default;
            Armour(std::string name, std::string description, unsigned def, Armour::Slot slo) : Item(name, description), defence(def), slot(slo)
            {
            }

            ~Armour() = default;

            unsigned defence;
            Slot slot;

        protected:
        private:

    };

}
#endif // ARMOUR_H
