#ifndef LOCATIONPARSER_HPP
#define LOCATIONPARSER_HPP

#include <string>
#include <map>
#include <utility> //std::pair
#include "Place.h"

namespace Taverner
{
    class LocationParser
    {
        public:
            LocationParser(std::string filepath);
            //This will return hash table of places. Places can be accessed by two ints: X and Y of place.
            std::map<std::pair<int, int>,  Place> Parse();
        protected:
        private:
            std::string m_filepath;
            inline int GetLocation(int x, int y, int m_mapX)
            {
                return x + y * m_mapX;
            }
    };
}

#endif // LOCATIONPARSER_HPP
