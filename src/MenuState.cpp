#include "MenuState.hpp"

#include "csout.hpp"

namespace Taverner
{
    MenuState::MenuState(Csout& csout) : userInput(-1)
    {
        //If I were Project Manager, I'd kill the programmer that would even suggest doing it that way
        //But since it's just Uni project... Sorry, Good Practice Spirit!
        //Concrete class!

        //We need to draw everything, since after constructor we will ask for
        //input first - not wise to expect answer to question that wasn't asked, eh?
        Draw(csout);
    }

    void MenuState::Pause()
    {
        GameState::Pause();
    }
    void MenuState::Resume()
    {
        GameState::Resume();
    }
    void MenuState::HandleEvents(std::string command)
    {
        if(!IsPaused())
        {
            //If input isn't in range, don't do anything
            if(userInput <= 0 || userInput > m_options.size())
            {

            }
            //Otherwise, select action that fits selection
            else
            {

            }

        }
    }
    void MenuState::Update(GameEngine* eng)
    {

    }
    void MenuState::Draw(Csout& csout)
    {
        if(!IsPaused())
        {
            //Greet our most welcome player
            csout << m_greet << Taverner::endl;
            //Number to present choices as ordered list
            int num = 0;
            //Present choices
            for(auto& element : m_options)
            {
                csout << ++num << ": " << element << Taverner::endl;
            }
        }
    }
}
