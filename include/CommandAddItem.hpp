#ifndef COMMANDADDITEM_HPP
#define COMMANDADDITEM_HPP

#include "Command.hpp"

namespace Taverner
{
    class Player;

    class CommandAddItem : public Command
    {

        public:
            CommandAddItem(int code);
            void Execute();
            void Draw(Csout& csout)
            {
                csout << "OK." << endl;
            }
            static void SetPlayer(Player* pl)
            {
                m_benefit = pl;
            }
        protected:
            static Player* m_benefit;
            int m_code;
        private:
    };
}
#endif // COMMANDADDITEM_HPP
