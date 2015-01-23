#ifndef PLACE_HPP
#define PLACE_HPP

#include <map>
#include <string>
#include "Item.h"
//Limitation: one creature per place.
namespace Taverner
{
    class Place
    {
        public:
            Place();
            void PrintEverything();
            void PrintItems();
            void PrintCreatures();

        protected:
        private:
            std::map<std::string, Item> m_inventory;
            int x,y;

    };
}
#endif // PLACE_HPP
