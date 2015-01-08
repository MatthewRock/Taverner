#ifndef CREATURE_H
#define CREATURE_H

#include <string>

#include EXP_MULTIPLIER 1

class Creature
{
    public:
        Creature(std::string nam, unsigned heal, unsigned str, unsigned intel, unsigned dex, unsigned wis, unsigned endur,
                 double hitCh, unsigned lev = 1, unsigned long exp = 0)
                 : name(nam), maxHealth(heal), strength(str), intelligence(intel), dexterity(dex), wisdom(wis), endurance(endur),
                 hitChance(hitCh), level(lev), experiencePoints(exp), currentHealth(heal)
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


        /** \brief Returns experience required to advance to given level
         *
         * \param lev unsigned
         *      Level for which experience will be specified.
         * \return unsigned
         *      Amount of experience points required to advance to level lev
         *
         */
        unsigned expToLevel(unsigned lev);



        /** \brief Levels up creature to next level if it meets requirements(xp)
         *
         * \return bool
         *
         */
        bool levelUp();

};

#endif // CREATURE_H
