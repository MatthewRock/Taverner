#include "GameEngine.hpp"

namespace Taverner
{
    void GameEngine::Update()
    {
        for(auto& x : states)
        {
            x->Update();
        }
    }

    void GameEngine::HandleEvents()
    {
        HandleEngineEvents();

        for(auto& x : states)
        {
            x->HandleEvents();
        }
    }

    void GameEngine::Draw()
    {
        for(auto& x : states)
        {
            x->Draw();
        }
    }

    void GameEngine::HandleEngineEvents()
    {

    }
}
