#ifndef CREATURE_H
#define CREATURE_H

#include <string>

#define EXP_MULTIPLIER 1

namespace Taverner
{
    class Creature
    {
        public:
            Creature() = default;
            Creature(const Creature& other) = default;
            Creature(std::string nam, unsigned heal, unsigned str, unsigned intel, unsigned dex, unsigned wis, unsigned endur,
                     double hitCh, std::string voc, unsigned lev = 1, unsigned long exp = 0)
                     : name(nam), maxHealth(heal), strength(str), intelligence(intel), dexterity(dex), wisdom(wis), endurance(endur),
                     hitChance(hitCh), vocation(voc), level(lev), experiencePoints(exp), currentHealth(heal)
             {

             }
            virtual ~Creature() = default;

            unsigned maxHealth;
            int currentHealth;
            unsigned strength;
            unsigned intelligence;
            unsigned dexterity;
            unsigned wisdom;
            unsigned endurance;

            double hitChance;

            unsigned level;
            unsigned long experiencePoints;

            std::string name;
            std::string vocation;

            unsigned expToLevel(unsigned lev);
            bool levelUp();

        private:
            inline int incStat(int mod)
            {
                return level % mod;
            }

    };
}
#endif // CREATURE_H
