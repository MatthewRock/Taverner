#ifndef PLACE_HPP
#define PLACE_HPP

#include <string>
#include <vector>
//#include "Item.h"
#include "NPC.hpp"
#include <memory>
#include "Command.hpp"

//Limitation: one creature per place.
namespace Taverner
{
    class Place
    {
        public:
// TODO (s407267#1#): Get this shit moving
            Place(std::string name, std::string desc, int x, int y, std::vector<NPC>&& npcs);
            void PrintEverything(Csout& csout);
            void PrintItems(Csout& csout);
            void PrintNPCs(Csout& csout);
            std::unique_ptr<Command> HandleEvents(std::string command);
        protected:
        private:
            int m_x, m_y;
            std::string m_name;
            std::string m_desc;
            std::vector<NPC> m_npcs;
    };
}
#endif // PLACE_HPP
