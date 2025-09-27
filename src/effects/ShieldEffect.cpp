#include "ShieldEffect.h"
#include "Character.h"

// Shield effect of Warrior on 2rd level
Damage ShieldEffect::TotalDamage(Damage baseDamage, const Character* attacker, const Character* target, int turnNumber) const
{
	return baseDamage;
}

Damage ShieldEffect::TotalDefense(Damage incomingDamage, const Character* defender, const Character* attacker, int turnNumber) const
{
	if (defender->getStrength() > attacker->getStrength())
	{
		return incomingDamage - 3;
	}
	return incomingDamage;
}
