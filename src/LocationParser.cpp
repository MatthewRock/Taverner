#include "LocationParser.hpp"

#include "rapidxml.hpp"
#include "rapidxml_utils.hpp"
#include <vector>
#include <utility> //std::pair
#include <regex>
namespace Taverner
{
    LocationParser::LocationParser(std::string filepath) : m_filepath(filepath)
    {
        //ctor
    }

    std::vector<Place> Parse()
    {

        //Create file for xml
        rapidxml::file<> xmlFile(m_filepath);
        rapidxml::xml_document<> doc;
        //Parse the file into the doc
        doc.parse<rapidxml::parse_declaration_node | rapidxml::parse_no_data_nodes>(xmlFile.data());

        std::vector<Place> result;
        //Now parsing begins!
        //For each "location" node
        for(rapidxml::xml_node<>* loc = doc.first_node("World")->first_node("location"); loc; loc = loc->next_sibling("location"))
        {
            //Get its properties
            std::string name = loc->first_node("name")->value();
            std::string desc = loc->first_node("description")->value();
            int x = atoi(loc->first_node("x")->value());
            int y = atoi(loc->first_node("y")->value());

            //If there are any items, load their IDS
            std::vector<int> itemIdVector;
            for(rapidxml::xml_node<>* itm = loc->first_node("item"); itm; itm = itm->next_sibling("item"))
            {
                vector.push_back(atoi(itm->value()));
            }
            // TODO (parchima#1#): Complete this function
            //std::vector<NPC> npcVector;
            for(rapidxml::xml_node<>* npc = loc->first_node("NPC"); npc; npc = npc->next_sibling("NPC"))
            {
                std::string npcName = npc->first_node("name")->value();
                //Pair regex : answer
                std::vector<std::pair<std::regex, std::string> > npcDialogues;
                for(rapidxml::xml_node<>* dialogue = npc->first_node("dialogue"); dialogue; dialogue = dialogue->next_sibling("dialogue"))
                {
                    std::string text = ".*" + npcName + R"((\s+.+\s+|\s+))" + dialogue->first_attribute()->value() + ".*;
                    std::string response = dialogue->value();
                    npcDialogues.push_back(std::make_pair(std::regex(text, std::regex_constants::ECMAScript | std::regex_constants::icase), response));
                }
            }
            //Then emplace Place object with these properties to the vector

            //result.emplace_back(Place(...))
        }
    }
}
