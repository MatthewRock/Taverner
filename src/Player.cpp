#include "Player.hpp"

namespace Taverner
{
    void Player::Move(int x, int y)
    {
        m_x += x;
        m_y += y;
    }
}
