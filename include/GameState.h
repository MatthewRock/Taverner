#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include <string>



namespace Taverner
{
    class GameEngine;
    class Csout;
    class GameState
    {
        public:

            //These two pure virtual functions have default implementations that can be called
            //in further implementations to pause/resume state(change paused flag)
            virtual void Pause() = 0;
            virtual void Resume() = 0;

            virtual void HandleEvents(std::string command) = 0;
            virtual void Update(GameEngine* eng) = 0;
            virtual void Draw(Csout& csout) = 0;

            GameState() = default;
            virtual ~GameState() = default;

            //We shouldn't be able to copy nor move state. Each state has specified role and fits on stack.
            //Allowing this would create possibility to break it.

            GameState(const GameState& other) = delete;
            GameState(GameState&&) = delete;
            GameState& operator=(const GameState& other) = delete;
            GameState& operator=(GameState&&) = delete;

            void ChangeState(GameEngine* game, GameState* state);
            inline bool IsPaused() { return m_paused; }

        protected:
        private:
            int m_paused;

    };

}
#endif // GAMESTATE_HPP
