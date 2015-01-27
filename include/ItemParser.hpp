#ifndef ITEMPARSER_HPP
#define ITEMPARSER_HPP

#include <string>
namespace Taverner
{
    class ItemParser
    {
        public:
            ItemParser(std::string filepath);
            void Parse();
        protected:
            std::string m_filepath;
        private:
    };
}
#endif // ITEMPARSER_HPP
