#include "Place.h"
#include "ItemsBank.h"
#include "CommandWrite.hpp"
#include "Logger.hpp"

namespace Taverner
{
    Place::Place(std::string name, std::string desc, int x, int y, std::vector<NPC>&& npcs, std::vector<std::pair<int, int> >&& items)
        : m_name(name), m_x(x), m_y(y), m_desc(desc), m_npcs(npcs), m_items(items)
    {
// TODO (s407267#1#): Insert regex to look around, at items, etc.
//Insert command "Describe surroundings"
            m_lookCommand       = std::regex (".*look.*", std::regex_constants::ECMAScript | std::regex_constants::icase);
            m_lookAroundCommand = std::regex(R"(.*look.*(\s+.+\s+|\s+)around.*)", std::regex_constants::ECMAScript | std::regex_constants::icase);

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
                return cmd;
        }
        //If we want to look around
        LOG_STRING("Npc look failed, looking around");
        if(regex_match(command, m_lookAroundCommand))
        {
            LOG_STRING("Look around matched");
            cmd = std::unique_ptr<Command>(new CommandWrite(m_desc));
            LOG_STRING("And created");
            return cmd;
            //Print everything and description of surroundings
        }
        //If we want to look at something's that's not NPC
        if(regex_match(command, m_lookCommand))
        {
            LOG_STRING("Look around failed but look matched");
            for(auto& item_pair : m_items)
            {
                LOG_STRING("Iterating over elements in items");
                auto itm = ItemsBank::GetInstance().GetItem(item_pair.first);
                std::string nameRegexStr = "";
                //If item exists(no error), print it.
                if(itm)
                {
                    nameRegexStr = R"(.*look.*(\s+.+\s+|\s+))" + itm->GetName() + ".*";
                    LOG_STRING("String created");
                    std::regex itemRegex(nameRegexStr, std::regex_constants::ECMAScript | std::regex_constants::icase);
                    LOG_STRING("regex created");
                    if(regex_match(command, itemRegex))
                    {
                        LOG_STRING("And matched");
                        cmd = std::unique_ptr<Command>(new CommandWrite(itm->GetDesc()));
                        LOG_STRING("And created");
                        return cmd;
                    }
                }
            }
        }


    }
}
