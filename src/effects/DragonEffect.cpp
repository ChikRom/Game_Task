#include "DragonEffect.h"


//Every 3rd turn,breathes fire,dealingan additional 3 damage
Damage DragonEffect::TotalDamage(Damage baseDamage, const Character* attacker, const Character* target, int turnNumber) const
{
    if (turnNumber % 3 == 0)
    {
        return baseDamage + 3;
    }
    return baseDamage;
}

Damage DragonEffect::TotalDefense(Damage incomingDamage, const Character* defender, const Character* attacker, int turnNumber) const
{
    return incomingDamage;
}
