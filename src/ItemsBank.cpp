#include "ItemsBank.h"
namespace Taverner
{
    Item* ItemsBank::GetItem(int index)
    {
        auto item = m_items.find(index);
        if(item != m_items.end())
            return item->second.get();

        return nullptr;
    }
    void ItemsBank::AddItem(int index, std::unique_ptr<Item> item)
    {
        m_items.emplace(index, std::move(item));
    }
    ItemsBank& ItemsBank::GetInstance()
    {
        static ItemsBank instance;

        return instance;
    }
}
