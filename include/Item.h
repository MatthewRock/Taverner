#ifndef ITEM_H
#define ITEM_H

#include <string>
namespace Taverner
{
    class Item
    {
        public:
            Item(std::string nam, std::string desc, int val) : m_name(nam), m_description(desc), m_value(val)
            {}
            ~Item() = default;
        protected:
            std::string m_name;
            std::string m_description;
            int m_value;
        private:
    };
}
#endif // ITEM_H
