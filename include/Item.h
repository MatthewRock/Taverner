#ifndef ITEM_H
#define ITEM_H

#include <string>
namespace Taverner
{
    class Item
    {
        public:
            Item(std::string nam, std::string desc) : name(nam), description(desc)
            {

            }
            ~Item() = default;
        protected:
        private:
            std::string name;
            std::string description;
            int value;

    };
}
#endif // ITEM_H
