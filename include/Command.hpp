#ifndef COMMAND_HPP
#define COMMAND_HPP

namespace Taverner
{
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
