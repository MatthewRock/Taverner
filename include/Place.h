#ifndef PLACE_HPP
#define PLACE_HPP

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
            int x,y;

    };
}
#endif // PLACE_HPP
