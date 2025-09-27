#include "StealthAttackEffect.h"
#include "Character.h"

// Stealth Attack 
// +1 damage if the character's agility
// is higher than the target's agility
Damage StealthAttackEffect::TotalDamage(Damage baseDamage, const Character* attacker, const Character* target, int turnNumber) const
{
	if (attacker->getAgility() > target->getAgility())
	{
		return baseDamage + 1;
	}
	return baseDamage;
}

Damage StealthAttackEffect::TotalDefense(Damage incomingDamage, const Character* defender, const Character* attacker, int turnNumber) const
{
	return incomingDamage;
}
