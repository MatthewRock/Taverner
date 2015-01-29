#include "CommandAddItem.hpp"

#include "Player.hpp"

namespace Taverner
{
    Player* CommandAddItem::m_benefit;
    CommandAddItem::CommandAddItem(int code)
    {
        m_code = code;
    }

    void CommandAddItem::Execute()
    {
        m_benefit->AddItem(m_code, 1);
    }
}
