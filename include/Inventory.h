#ifndef INVENTORY_H
#define INVENTORY_H

#include "Item.h"
#include "Weapon.h"
#include "Armour.h"

#include <vector>
#include <utility>
#include <memory>


namespace Taverner
{

    class Inventory
    {
        public:
            Inventory() = default;
// TODO (malice#1#): Prepare for adding items using Item Manager.

            void addItem(){};
        protected:
        private:
            std::vector<std::pair<std::unique_ptr<Item>, int> > items;
            std::vector<std::pair<std::unique_ptr<Weapon>, int> > weapons;
            std::vector<std::pair<std::unique_ptr<Armour>, int> > armour;
    };

}
#endif // INVENTORY_H
