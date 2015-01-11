#ifndef WEAPON_H
#define WEAPON_H

#include "Item.h"

namespace Taverner
{
    class Weapon : public Item
    {
        public:
            Weapon() = default;
            Weapon(std::string name, std::string description, unsigned dam, double hitCh) : Item(name, description), damage(dam), hitChanceMod(hitCh)
            {
            }
            ~Weapon() = default;

            unsigned damage;
            double hitChanceMod;

        protected:
        private:
    };
}
#endif // WEAPON_H
