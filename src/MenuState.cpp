#include "MenuState.hpp"

#include "csout.hpp"

namespace Taverner
{
    MenuState::MenuState() : userInput(-1)
    {
        //If I were Project Manager, I'd kill the programmer that would even suggest doing it that way
        //But since it's just Uni project... Sorry, Good Practice Spirit!
        //Concrete class!
        m_greet = "Welcome to Taverner! Please, select option:";
        m_options = {"New game", "Choose scenario", "Credits", "Exit"};

        //We need to draw everything, since after constructor we will ask for
        //input first - not wise to expect answer to question that wasn't asked, eh?
        Draw();
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
    void MenuState::Draw()
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
