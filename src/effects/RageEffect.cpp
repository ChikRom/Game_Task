#include "RageEffect.h"

//Rage effect of Barbarian on 1rd level
Damage RageEffect::TotalDamage(Damage baseDamage, const Character* attacker, const Character* target, int turnNumber) const
{
	if (turnNumber <= 3)
	{
		return baseDamage + 2;
	}
	return baseDamage - 1;
}

Damage RageEffect::TotalDefense(Damage incomingDamage, const Character* defender, const Character* attacker, int turnNumber) const
{
	return incomingDamage;
}
