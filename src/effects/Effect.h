#pragma once
#include "Types.h"


class Character;
//Abstract class for bonuses of characters
class Effect
{
public:
	virtual Damage TotalDamage(Damage baseDamage, const Character* attacker,const Character* target,int turnNumber) const = 0;
	virtual Damage TotalDefense(Damage incomingDamage, const Character* defender,const Character* attacker, int turnNumber) const = 0;
	virtual ~Effect() = default;
};