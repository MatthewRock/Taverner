#include "Dialogue.h"
namespace Taverner
{
    Dialogue::Dialogue(const Dialogue& other)
    {
        //copy ctor
    }

    Dialogue::Dialogue(std::string qst, std::vector<std::string> ch) : question(qst), choices(ch)
    {

    }

    Dialogue::Dialogue(const Dialogue&& other) : question(std::move(other.question)), choices(std::move(other.choices))
    {

    }

    int Dialogue::activate()
    {
        //Ask question in dialogue
        std::cout << question << std::endl;
        //Number to present choices as ordered list
        int num = 0;
        //Present choices
        for(auto& element : choices)
        {
            std::cout << ++num << ": " << element << std::endl;
        }

        //We answered for user, and it wasn't valid answer. :)

        int userInput = -1;
        //Ask user for answer until the answer is in range.
        while(userInput < 0 || userInput > choices.size())
        {
            std::cin >> userInput;
        }

        //At this point we got valid answer
        return userInput;
    }
}
