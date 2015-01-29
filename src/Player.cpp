#include "Player.hpp"

namespace Taverner
{
    Player::Player()
    {
        m_x = 0;
        m_y = 0;
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
}
