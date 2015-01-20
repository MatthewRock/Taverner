#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <Creature.h>


class Player : public Creature
{
    public:
        Player();

        ~Player();
    protected:
    private:
        int x,y;
};

#endif // PLAYER_HPP

//Scheme:
//Create World that will hold Player and Map.
//World handles player input by checking if he can move in Map.
//For now, moving suffices
