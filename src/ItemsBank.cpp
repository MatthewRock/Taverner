#include "ItemsBank.h"
#include "Logger.hpp"
namespace Taverner
{
    Item* ItemsBank::GetItem(int index)
    {
        auto item = m_items.find(index);
        if(item != m_items.end())
            return item->second;

        return nullptr;
    }
    void ItemsBank::AddItem(int index, Item* item)
    {
        m_items.emplace(index, item);
    }
    ItemsBank& ItemsBank::GetInstance()
    {
        static ItemsBank instance;

        return instance;
    }
    ItemsBank::~ItemsBank()
    {
        for(auto& el : m_items)
            delete el.second;
    }
}
