#include "Creature.h"
#include <iostream>
namespace Taverner
{

    /** \brief Returns experience required to advance to given level
     *
     * \param lev unsigned
     *      Level for which experience will be specified.
     * \return unsigned
     *      Amount of experience points required to advance to level lev
     *
     */
    unsigned Creature::expToLevel(unsigned lev)
    {
        //Some arbitrary hard-coded XP formula.
        return 80 * lev * lev * EXP_MULTIPLIER;
    }

    /** \brief Levels up creature to next level if it meets requirements(xp)
     *
     * \return bool
     *
     */
    bool Creature::levelUp()
    {
        if(experiencePoints >= expToLevel(level + 1))
        {
            //Level up
            ++level;
            //Increase health
            maxHealth += (level + endurance) * 10;
            //As a bonus, regenerate hp to max.
            currentHealth = maxHealth;
            //Increase Creature's stats according to their vocation
            if(vocation == "Warrior")
            {
                strength += incStat(10);
                endurance += incStat(9);
                dexterity += incStat(5);
                intelligence += incStat(3);
                wisdom += incStat(3);
            }
            else if(vocation == "Rogue")
            {
                dexterity += incStat(10);
                strength += incStat(7);
                endurance += incStat(5);
                intelligence += incStat(4);
                wisdom += incStat(3);
            }
            else if(vocation == "Wizard")
            {
                intelligence += incStat(10);
                wisdom += incStat(7);
                dexterity += incStat(5);
                endurance += incStat(4);
                strength += incStat(3);
            }
            else if(vocation == "Priest")
            {
                wisdom += incStat(10);
                intelligence += incStat(7);
                endurance += incStat(5);
                dexterity += incStat(4);
                strength += incStat(3);
            }
            std::cout << "Congratulations! " << name << " has levelled up to level " << level << "!" << std::endl;
        }
    }
}
