#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

namespace Taverner
{

    class GameState
    {
        public:
            virtual void Pause() = 0;
            virtual void Resume() = 0;
            virtual void HandleEvents() = 0;
            virtual void Update() = 0;
            virtual void Draw() = 0;
            virtual void ChangeState() = 0;

            GameState() = default;
            GameState(const GameState& other) = default;
            GameState(GameState&&) = default;
            GameState& operator=(const GameState& other) & = default;
            GameState& operator=(GameState&&) & = default;
            virtual ~GameState() = default;

        protected:
        private:
    };

}
#endif // GAMESTATE_HPP
