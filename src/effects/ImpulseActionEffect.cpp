#include "ImpulseActionEffect.h"
#include "Character.h"


// Impulse to action (warrior)
Damage ImpulseActionEffect::TotalDamage(Damage baseDamage, const Character* attacker, const Character* target, int turnNumber) const
{
    if (turnNumber == 1)
    {
        return baseDamage + attacker->getWeapon()->damage;
    }
    return baseDamage;
}

Damage ImpulseActionEffect::TotalDefense(Damage incomingDamage, const Character* defender, const Character* attacker, int turnNumber) const
{
    return incomingDamage;
}
