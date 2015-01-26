#include "Place.h"
namespace Taverner
{
    Place::Place(std::string name, std::string desc, int x, int y, std::vector<NPC>&& npcs)
        : m_name(name), m_desc(desc), m_x(x), m_y(y), m_npcs(npcs)
    {
// TODO (s407267#1#): Insert regex to look around, at items, etc.

    }
    void Place::PrintEverything(Csout& csout)
    {

    }
    void Place::PrintItems(Csout& csout)
    {

    }
    void Place::PrintNPCs(Csout& csout)
    {

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
