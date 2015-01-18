#include "GameEngine.hpp"

#include "MenuState.hpp"
#include "csout.hpp"
namespace Taverner
{
    GameEngine::GameEngine()
    {
        m_running = true;
        m_states.emplace_back(new MenuState(m_csout));
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
        if(ch == "q")
        {
            Quit();
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
