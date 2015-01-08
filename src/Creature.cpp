#include "Creature.h"

namespace Taverner
{
    unsigned Creature::expToLevel(unsigned lev)
    {
        //Some arbitrary hard-coded XP formula.
        return 128 * lev * lev * EXP_MULTIPLIER;
    }

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
            if(vocation == "Warrior")
            {
                strength += level / 10;
            }
            else if(vocation == "")

        }
    }
}
