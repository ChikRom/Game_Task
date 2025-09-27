#include "PoisonEffect.h"

// Poison effect of Robber on 3rd level
Damage PoisonEffect::TotalDamage(Damage baseDamage, const Character* attacker, const Character* target, int turnNumber) const
{
    return baseDamage + (turnNumber - 1);
}

Damage PoisonEffect::TotalDefense(Damage incomingDamage, const Character* defender, const Character* attacker, int turnNumber) const
{
    return incomingDamage;
}
