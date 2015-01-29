#include "Player.hpp"
#include "ItemsBank.h"
#include "Logger.hpp"
#include <algorithm>

namespace Taverner
{
    Player::Player() : m_equippedWpn(nullptr)
    {
        m_x = 0;
        m_y = 0;
        m_atk = 10;
        m_def = 10;
        m_moved = false;
        m_hp = 10;
        for(int i = 0; i < SLOT_N; ++i)
        {
            m_equippedArmour[i] = nullptr;
        }
    }
    void Player::Move(int x, int y)
    {
        m_x += x;
        m_y += y;
        m_moved = true;
    }
    void Player::AddItem(int code, int quantity)
    {
        for(auto& elem : m_equipement)
        {
            if(elem.first == code)
            {
                elem.second += quantity;
                return;
            }
        }
        m_equipement.push_back(std::make_pair(code, quantity));
    }
    void Player::RemoveItem(int code, int quantity)
    {
        for(auto it = m_equipement.begin(); it != m_equipement.end(); ++it)
        {
            if(it->first == code)
            {
                if(it->second <= quantity)
                {
                    m_equipement.erase(it);
                    return;
                }
                else
                {
                    it->second -= quantity;
                    return;
                }
            }
        }
    }
    void Player::PrintItems(Csout& csout)
    {
        bool visited = false;
        for(auto& elem : m_equipement)
        {
            visited = true;
            csout << "You have " << elem.second << ' ' << ItemsBank::GetInstance().GetItem(elem.first)->GetName() << "(s)" << endl;
        }
        if(!visited)
            csout << "You have no items." << endl;
    }
    bool Player::Equip(std::string& item)
    {
        std::string itemName = item.substr(6);
        std::transform(itemName.begin(), itemName.end(), itemName.begin(), ::tolower);

        for(auto& elem : m_equipement)
        {
            std::string realName = ItemsBank::GetInstance().GetItem(elem.first)->GetName();
            std::transform(realName.begin(), realName.end(), realName.begin(), ::tolower);
            if(realName == itemName)
            {
                ITEM_TYPE itemID = ItemsBank::GetInstance().GetItem(elem.first)->GetType();
                LOG_STRING(std::to_string(itemID));
                if(itemID == ITEM_WEAPON)
                    m_equippedWpn = static_cast<Weapon*>(ItemsBank::GetInstance().GetItem(elem.first));
                else if (itemID == ITEM_ARMOUR)
                {
                    m_equippedArmour[static_cast<Armour*>(ItemsBank::GetInstance().GetItem(elem.first))->GetSlot()] = static_cast<Armour*>(ItemsBank::GetInstance().GetItem(elem.first));
                }
                else
                    return false;

                return true;
            }
        }
        return false;
    }
    void Player::PrintStats(Csout& csout)
    {
        csout << "My hp: " << m_hp << endl;
        csout << "My attack: " << m_atk << endl;
        csout << "My defence: " << m_def << endl;
        if(m_equippedWpn)
        {
            csout << "My weapon is " << m_equippedWpn->GetName() << endl << m_equippedWpn->GetDesc() << endl;
            csout << "It has " << m_equippedWpn->GetDamage() << " points of damage, and " << m_equippedWpn->GetDefence() << " points of defence." << endl;
        }
        for(int i = 0; i < SLOT_N; ++i)
        {
            if(m_equippedArmour[i])
            {
                csout << "I am wearing " << m_equippedArmour[i]->GetName() << endl << m_equippedArmour[i]->GetDesc() << endl
                      << "It grants me " << m_equippedArmour[i]->GetDef() << "points of defence."  << endl;
            }
        }

    }
}
