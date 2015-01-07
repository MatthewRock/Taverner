#ifndef DIALOGUE_H
#define DIALOGUE_H

#include <iostream>
#include <vector>
#include <string>

namespace Taverner
{
    class Dialogue
    {
        public:
            Dialogue(std::string question, std::vector<std::string> choices);
            ~Dialogue() = default;
            Dialogue(const Dialogue& other);
            Dialogue(const Dialogue&& other);

            /** \brief Asks the player for answer to the question, until the answer is right.
             *
             * \return int number meaning which choice was chosen
             *
             */
            int activate();
        protected:
        private:
            std::string question;
            std::vector<std::string> choices;
    };
}
#endif // DIALOGUE_H
