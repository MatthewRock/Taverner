#include "Place.h"
#include "ItemsBank.h"

namespace Taverner
{
    Place::Place(std::string name, std::string desc, int x, int y, std::vector<NPC>&& npcs, std::vector<std::pair<int, int> >&& items)
        : m_name(name), m_x(x), m_y(y), m_desc(desc), m_npcs(npcs), m_items(items)
    {
// TODO (s407267#1#): Insert regex to look around, at items, etc.


    }
    void Place::PrintEverything(Csout& csout)
    {
        csout << "You are at " << m_name << endl;
        PrintNPCs(csout);
        PrintItems(csout);
    }
    void Place::PrintItems(Csout& csout)
    {
        for(auto& item_pair : m_items)
        {
            //itm is pointer to item
            auto itm = ItemsBank::GetInstance().GetItem(item_pair.first);
            std::string itemName = "";
            //If item exists(no error), print it.
            if(itm)
                itemName = itm->GetName() + "(s)";

            csout << "You see " << item_pair.second << " " << itemName << endl;
        }
    }
    void Place::PrintNPCs(Csout& csout)
    {
        for(auto& npc : m_npcs)
        {
            csout << "You see " << npc.GetName() << endl;
        }
    }
    std::unique_ptr<Command> Place::HandleEvents(std::string command)
    {
        std::unique_ptr<Command> cmd = nullptr;
        for(auto& npc : m_npcs)
        {
            cmd = npc.HandleEvents(command);

            if(cmd)
                break;
        }
        return cmd;
    }
}
