#ifndef ITEM_H
#define ITEM_H

#include <string>
namespace Taverner
{
    enum ITEM_TYPE
    {
        ITEM_DEFAULT,
        ITEM_WEAPON,
        ITEM_ARMOUR,
        ITEM_N,
    };
    class Item
    {
        public:
            Item(std::string nam, std::string desc, int val, ITEM_TYPE type = ITEM_DEFAULT)
            : m_name(nam), m_description(desc), m_value(val), m_type(type)
            {}
            ~Item() = default;
            inline ITEM_TYPE GetType() { return m_type; }
        protected:
            std::string m_name;
            std::string m_description;
            int m_value;
            ITEM_TYPE m_type;

        private:
    };
}
#endif // ITEM_H
