#ifndef LOCATIONPARSER_HPP
#define LOCATIONPARSER_HPP

#include <string>
#include <vector>
#include "Place.h"

namespace Taverner
{
    class LocationParser
    {
        public:
            LocationParser(std::string filepath);
            std::vector<Place> Parse();
        protected:
        private:
            std::string m_filepath;
    };
}

#endif // LOCATIONPARSER_HPP
