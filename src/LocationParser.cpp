#include "LocationParser.hpp"

#include "rapidxml.hpp"
#include "rapidxml_utils.hpp"
#include <vector>
#include <utility> //std::pair
#include <regex>
#include "NPC.hpp"
#include <algorithm> //find_if
namespace Taverner
{
    LocationParser::LocationParser(std::string filepath) : m_filepath(filepath)
    {
        //ctor
    }

    std::map<std::pair<int, int>, Place> LocationParser::Parse()
    {

        //Create file for xml
        rapidxml::file<> xmlFile(m_filepath.c_str());
        rapidxml::xml_document<> doc;
        //Parse the file into the doc
        doc.parse<rapidxml::parse_declaration_node | rapidxml::parse_no_data_nodes>(xmlFile.data());

        //Resulting place vector.
        std::map<std::pair<int, int>, Place> result;

        //Now parsing begins!
        //For each "location" node
        for(rapidxml::xml_node<>* loc = doc.first_node("World")->first_node("location"); loc; loc = loc->next_sibling("location"))
        {
            //Get its properties
            std::string name = loc->first_node("name")->value();
            std::string desc = loc->first_node("description")->value();
            int x = std::stoi(loc->first_node("x")->value());
            int y = std::stoi(loc->first_node("y")->value());
            //Everything above will build skeleton of location. Now, put NPCS and items in it.
            std::vector<std::pair<int, int> > itemIdVector;
            std::vector<NPC> npcVector;

            //If there are any items, load their IDS
            for(rapidxml::xml_node<>* itm = loc->first_node("item"); itm; itm = itm->next_sibling("item"))
            {
                LOG_STRING("No segfault yet. No itm initialized.");
                auto qt = itm->first_attribute("quantity");
                int quantity = 1;
                if(itm)
                    quantity = std::stoi(qt->value());

                itemIdVector.push_back(std::make_pair(std::stoi(itm->value()), quantity));
                LOG_STRING("No segfault yet. Pushed vector");
            }

            //If there are any NPCs, load them to vector
            LOG_STRING("If nothing is below me, no NPC was created");
            for(rapidxml::xml_node<>* npc = loc->first_node("npc"); npc; npc = npc->next_sibling("npc"))
            {
                LOG_STRING("Creating NPC:");
                std::string npcName = npc->first_node("name")->value();
                LOG_STRING(npcName);
                std::string npcDesc = npc->first_node("description")->value();
                LOG_STRING(npcDesc);
                //Pair regex - answer
                std::vector<std::pair<std::regex, std::string> > npcDialogues;
                for(rapidxml::xml_node<>* dialogue = npc->first_node("dialogue"); dialogue; dialogue = dialogue->next_sibling("dialogue"))
                {
                    std::string text = ".*" + npcName + R"((\s+.+\s+|\s+))" + dialogue->first_attribute()->value() + ".*";
                    std::string response = dialogue->value();
                    //Trim the value - because string comes in raw form, it can contain unnecessary whitespaces.
                    response = regex_replace(response, std::regex("\\s+"), " ");
                    //Change all whitespace to space
                    //If string had leading whitespace, remove it.
                    if(response[0] == ' ')
                        response.erase(response.begin());

                    LOG_STRING(text);
                    LOG_STRING(response);
                    npcDialogues.push_back(std::make_pair(std::regex(text, std::regex_constants::ECMAScript | std::regex_constants::icase), response));
                }
                npcVector.emplace_back(npcName, npcDesc, npcDialogues);
            }

// TODO (s407267#1#): Add monsters and allow parsing them here
            //Then emplace Place object with these properties to the vector

            result.emplace(std::make_pair(x,y), Place(name, desc, x, y, std::move(npcVector), std::move(itemIdVector)));

        }
        return result;
    }
}
