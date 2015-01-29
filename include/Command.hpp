#ifndef COMMAND_HPP
#define COMMAND_HPP

#include "csout.hpp"

namespace Taverner
{
    class Player;

    class Command
    {
        public:
            virtual ~Command() = default;
            virtual void Execute() = 0;
            virtual void Draw(Csout& csout) = 0;
        protected:
        private:
    };
}
#endif // COMMAND_HPP
