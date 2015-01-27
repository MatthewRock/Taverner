#ifndef ITEMSBANK_H
#define ITEMSBANK_H

#include "Item.h"
#include <memory>
#include <map>

//Singleton time!
namespace Taverner
{
    //ItemsBank will be holding all item objects, so that eq can contain only ID of item and its quantity
    class ItemsBank
    {
        public:
            ~ItemsBank() = default;
            void AddItem(int index, std::unique_ptr<Item> item);
            Item* GetItem(int index);
            static ItemsBank& GetInstance();

        protected:
            ItemsBank() {};
            ItemsBank(ItemsBank const&);
            void operator=(ItemsBank const&);
        private:
            std::map<int, std::unique_ptr<Item> > m_items;
    };
}

#endif // ITEMSBANK_H
