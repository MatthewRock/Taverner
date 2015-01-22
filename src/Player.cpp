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
    }
}
