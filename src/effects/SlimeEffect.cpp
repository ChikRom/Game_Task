#include "SlimeEffect.h"
#include "Character.h"


Damage SlimeEffect::TotalDamage(Damage baseDamage, const Character* attacker, const Character* target, int turnNumber) const
{
    return baseDamage;
}


// Slime effect - slashing weapons do no damage to Slime
Damage SlimeEffect::TotalDefense(Damage incomingDamage, const Character* defender, const Character* attacker, int turnNumber) const
{
    if (attacker->getWeapon()->type == DamageType::Slashing)
    {
        return incomingDamage - attacker->getWeapon()->damage;
    }
    return incomingDamage;
}
