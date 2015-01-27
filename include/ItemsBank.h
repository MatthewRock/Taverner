#ifndef ITEMSBANK_H
#define ITEMSBANK_H

#include "Item.h"
#include <memory>
#include <map>

namespace Taverner
{
    class ItemsBank
    {
        public:
            ItemsBank() = default;
            ~ItemsBank() = default;
            void AddItem(int index, std::unique_ptr<Item> item);
            Item* GetItem(int index);
        protected:
        private:
            std::map<int, std::unique_ptr<Item> > m_items;
    };
}

#endif // ITEMSBANK_H
