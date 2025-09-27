#include "StoneSkinEffect.h"
#include "Character.h"
Damage StoneSkinEffect::TotalDamage(Damage baseDamage, const Character* attacker, const Character* target, int turnNumber) const
{
	return baseDamage;
}



// Stone skin effect 
// Damage taken is reduced by the amount of your endurance (Barbarian and Golem)
Damage StoneSkinEffect::TotalDefense(Damage incomingDamage, const Character* defender, const Character* attacker, int turnNumber) const
{
	Damage finalDamage = incomingDamage - defender->getEndurance();
	return (finalDamage > 0) ? finalDamage : 0;
}
