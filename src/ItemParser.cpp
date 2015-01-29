#include "ItemParser.hpp"

#include "rapidxml.hpp"
#include "rapidxml_utils.hpp"
#include "Item.h"
#include "Weapon.h"
#include "Armour.h"
#include "ItemsBank.h"

#include "Logger.hpp"

namespace Taverner
{
    ItemParser::ItemParser(std::string filepath) : m_filepath(filepath)
    {

    }
    void ItemParser::Parse()
    {
        //Create file for xml
        rapidxml::file<> xmlFile(m_filepath.c_str());
        rapidxml::xml_document<> doc;
        //Parse the file into the doc
        doc.parse<rapidxml::parse_declaration_node | rapidxml::parse_no_data_nodes>(xmlFile.data());
        for(rapidxml::xml_node<>* itm = doc.first_node("World")->first_node("item"); itm; itm = itm->next_sibling("item"))
        {
            int value = std::stoi(itm->first_node("val")->value());
            int ID = std::stoi(itm->first_node("ID")->value());
            std::string name = itm->first_node("name")->value();
            std::string description = itm->first_node("description")->value();
            //Get items type
            auto type = itm->first_attribute("quantity");
            //if it has type, it's either weapon or armor: proceed with their creation.
            if(type)
            {
                int def = std::stoi(itm->first_node("def")->value());
                if(type->value() == "weapon")
                {
                    unsigned atk = std::stoi(itm->first_node("atk")->value());
                    ItemsBank::GetInstance().AddItem(ID, new Weapon(name, description, value, atk, def));
                }
                else if(type->value() == "armour")
                {
                    int slot = std::stoi(itm->first_node("slot")->value());
                    ItemsBank::GetInstance().AddItem(ID, new Armour(name, description, value, def, slot));
                }
            }
            //Otherwise it's plain boring item.
            else
            {
                ItemsBank::GetInstance().AddItem(ID, new Item(name, description, value));
            }

        }
    }
}
