#include "GameEngine.hpp"

#include "World.hpp"
#include "csout.hpp"
namespace Taverner
{
    GameEngine::GameEngine()
    {
        m_running = true;
        m_states.emplace_back(new World(m_csout));
        // Regex matching "exit", with anything before and after. Case-insensitive.
        AddRegex(".*exit.*", COMMAND_EXIT);
    }

    void GameEngine::Update()
    {
        for(auto& x : m_states)
        {
            x->Update(this);
        }
    }

    void GameEngine::HandleEvents()
    {
        std::string ch = m_parser.GetInput(m_csout);
        //Clear screen
        m_csout.CrMove(0,0);
        clrtobot();
        HandleEngineEvents(ch);

        for(auto& x : m_states)
        {
            x->HandleEvents(ch);
        }
    }

    void GameEngine::Draw()
    {
        for(auto& x : m_states)
        {
            x->Draw(m_csout);
        }
    }

    void GameEngine::HandleEngineEvents(std::string ch)
    {
        int answerCode = COMMAND_N;
        //m_csout << "String: " << ch << endl;
        for(auto& elem : m_commands)
        {
            if(std::regex_match(ch, elem.first))
            {
                m_csout << "Regex matched!" << endl;
                answerCode = elem.second;
                break;
            }
        }
        switch(answerCode)
        {
        case COMMAND_EXIT:
            Quit();
            break;
        case COMMAND_N:
        default:
            break;
            //No command was choosen, or command unimplemented.
        }
    }
    void GameEngine::ChangeState(GameState* state)
    {
        if(!m_states.empty())
        {
            m_states.pop_back();
        }

        m_states.push_back(std::unique_ptr<GameState>(state));
    }
    void GameEngine::PushState(GameState* state)
    {
        if(!m_states.empty())
        {
            m_states.back()->Pause();
        }
        m_states.push_back(std::unique_ptr<GameState>(state));
    }
    void GameEngine::PopState()
    {
        if(!m_states.empty())
        {
            m_states.pop_back();
        }
        if(!m_states.empty())
        {
            m_states.back()->Resume();
        }
    }

}
