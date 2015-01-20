#ifndef PLACE_H
#define PLACE_H

//Limitation: one creature per place.
class Place
{
    public:
        Place();
        PrintEverything();
        PrintItems();
        PrintCreatures();

    protected:
    private:
        int x,y;

};

#endif // PLACE_H
