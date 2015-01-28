#ifndef PLACE_HPP
#define PLACE_HPP

#include <string>
#include <vector>
//#include "Item.h"
#include "NPC.hpp"
#include <memory>
#include <regex>
#include <utility> //std::pair
#include "Command.hpp"

//Limitation: one creature per place.
namespace Taverner
{
    class Place
    {
        public:
            Place(std::string name, std::string desc, int x, int y, std::vector<NPC>&& npcs, std::vector<std::pair<int, int> >&& items);
            void PrintEverything(Csout& csout);
            void PrintItems(Csout& csout);
            void PrintNPCs(Csout& csout);
            std::unique_ptr<Command> HandleEvents(std::string& command);
        protected:
        private:
            int m_x, m_y;
            std::string m_name;
            std::string m_desc;
            std::vector<NPC> m_npcs;
            //Item ID, quantity
            std::vector<std::pair<int, int> > m_items;
            std::vector<std::pair<std::regex, std::string> > m_dialogues;
            std::regex m_lookCommand;
            std::regex m_lookAroundCommand;
            std::regex m_takeCommand;

            std::unique_ptr<Command> HandleLookCommand(std::string& command);
            std::unique_ptr<Command> HandleTakeCommand(std::string& command);

    };
}
#endif // PLACE_HPP
