#include <iostream>

#include <stdexcept>
//TODO:
// TODO (malice#1#): Inspect multiwindows in ncurses
#include "GameEngine.hpp"
#include "csout.hpp"
using namespace Taverner;

int main(int argc, char* argv[])
{


    GameEngine SUD;
// TODO (malice#1#): Csout must be declared after GameEngine(or at least Initializer's constructor).

    csout<< "Hello, world!";
    getch();

    //SUD.Run();

    return 0;
}
//
//Creature dialogue_newchar()
//{
//    std::string name;
//    std::cout <<"Choose the name for your character: ";
//    //Somehow, Dialogue would make getline not triggered.
//    std::cin.ignore();
//
//    std::getline(std::cin, name);
//    int result = Dialogue("Choose your class.",
//                          {"Warrior", "Rogue", "Wizard", "Priest"}).activate();
//    switch(result)
//    {
//    case 1:
//        return Creature(name, 100, 10, 3, 5, 3, 9, "Warrior");
//        break;
//    case 2:
//        return Creature(name, 100, 7, 4, 10, 3, 5, "Rogue");
//        break;
//    case 3:
//        return Creature(name, 100, 3, 10, 5, 7, 4, "Wizard");
//        break;
//    case 4:
//        return Creature(name, 100, 3, 7, 4, 10, 5, "Priest");
//        break;
//    default:
//        std::string error = "Reached default clausule in switch where this shouldn't be the case. Function: dialogue_newchar. ";
//        std::cout << result << std::endl;
//        throw(std::runtime_error(error));
//    }
//
//}
