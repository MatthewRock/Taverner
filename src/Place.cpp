#include "Place.h"
#include "ItemsBank.h"
#include "CommandWrite.hpp"
#include "Logger.hpp"
#include "CommandAddItem.hpp"
#include "Item.h"
#include "Weapon.h"
#include "Armour.h"

namespace Taverner
{
    Place::Place(std::string name, std::string desc, int x, int y, std::vector<NPC>&& npcs, std::vector<std::pair<int, int> >&& items)
        : m_name(name), m_x(x), m_y(y), m_desc(desc), m_npcs(npcs), m_items(items)
    {
            m_lookCommand       = std::regex (".*look.*", std::regex_constants::ECMAScript | std::regex_constants::icase);
            m_lookAroundCommand = std::regex(R"(.*look.*(\s+.+\s+|\s+)around.*)", std::regex_constants::ECMAScript | std::regex_constants::icase);
            m_takeCommand       = std::regex(R"(.*take.*)", std::regex_constants::ECMAScript | std::regex_constants::icase);
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
            {
                itemName = itm->GetName() + "(s)";
                LOG_STRING("Item found:");
                LOG_STRING(itemName);
            }


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
    std::unique_ptr<Command> Place::HandleEvents(std::string& command)
    {
        std::unique_ptr<Command> cmd = nullptr;
        for(auto& npc : m_npcs)
        {
            cmd = npc.HandleEvents(command);

            if(cmd)
                return cmd;
        }
        //To look at everything except NPC(npc handle it themselves)
        cmd = HandleLookCommand(command);
        //if player wanted to look, send command, otherwise continue
        if(cmd)
            return cmd;

        cmd = HandleTakeCommand(command);
        if(cmd)
            return cmd;


    }
    std::unique_ptr<Command> Place::HandleLookCommand(std::string& command)
    {
        std::unique_ptr<Command> cmd = nullptr;
        //If player wants to "look around"
        if(regex_match(command, m_lookAroundCommand))
        {
            //Print description of the place we're at.
            cmd = std::unique_ptr<Command>(new CommandWrite(m_desc));
            return cmd;
        }
        //If we want to look at something's that's not NPC
        if(regex_match(command, m_lookCommand))
        {
            for(auto& item_pair : m_items)
            {
                auto itm = ItemsBank::GetInstance().GetItem(item_pair.first);
                std::string nameRegexStr = "";
                //If item exists(no error), print it.
                if(itm)
                {
                    //Create item regex
                    nameRegexStr = R"(.*look.*(\s+.+\s+|\s+))" + itm->GetName() + ".*";
                    std::regex itemRegex(nameRegexStr, std::regex_constants::ECMAScript | std::regex_constants::icase);
                    //If player asked for this item
                    if(regex_match(command, itemRegex))
                    {
                        cmd = std::unique_ptr<Command>(new CommandWrite(itm->GetDesc()));
                        //Return proper command
                        return cmd;
                    }
                }
            }
        }
        return cmd;//equal to return nullptr
    }
    std::unique_ptr<Command> Place::HandleTakeCommand(std::string& command)
    {
        std::unique_ptr<Command> cmd = nullptr;
        //If player said he wants to "take" something
        if(regex_match(command, m_takeCommand))
        {
            //Then let's loop over items
            for(auto it = m_items.begin(); it != m_items.end(); ++it)
            {
                auto itm = ItemsBank::GetInstance().GetItem(it->first);
                std::string nameRegexStr = "";
                //If item exists(no error), check for taking it.
                if(itm)
                {
                    //Create item regex
                    nameRegexStr = R"(.*take.*(\s+.+\s+|\s+))" + itm->GetName() + ".*";
                    std::regex itemRegex(nameRegexStr, std::regex_constants::ECMAScript | std::regex_constants::icase);
                    //If player asked for this item
                    if(regex_match(command, itemRegex))
                    {
                        //Send command to return this item
                        //Command will have item code
                        cmd = std::unique_ptr<Command>(new CommandAddItem(it->first));
                        //Now change amount of these items in place, by one.
                        it->second -= 1;
                        if(it->second <= 0)
                        {
                            m_items.erase(it);
                        }
                        //Return proper command
                        return cmd;
                    }
                }
            }
        }
        return cmd;
    }
}
