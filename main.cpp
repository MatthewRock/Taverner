#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <utility>
#include "Timer.hpp"

#include <stdexcept>

#include "Dialogue.h"
#include "Creature.h"

using namespace Taverner;

Creature dialogue_newchar();

int main(int argc, char* argv[])
{
    Creature player;
    int result = Dialogue(
    "Welcome!",
    {"New Game", "Exit"}).activate();

    switch(result)
    {
        case 1: player = dialogue_newchar(); break;
        default: return 0; break;
    }

    return 0;
}

Creature dialogue_newchar()
{
    std::string name;
    std::cout <<"Choose the name for your character: ";
    std::getline(std::cin, name);

    int result = Dialogue("Choose your class.",
                          {"Warrior", "Rogue", "Wizard", "Priest"}).activate();
    switch(result)
    {
    case 1:
        return Creature(name, 100, 10, 3, 5, 3, 9, 10.0, "Warrior");
        break;
    case 2:
        return Creature(name, 100, 7, 4, 10, 3, 5, 15.0, "Rogue");
        break;
    case 3:
        return Creature(name, 100, 3, 10, 5, 7, 4, 10.0, "Wizard");
        break;
    case 4:
        return Creature(name, 100, 3, 7, 4, 10, 5, 10.0, "Priest");
        break;
    default:
        throw(std::runtime_error("Reached default clausule in switch where this shouldn't be the case. Function: dialogue_newchar."));
    }

}
