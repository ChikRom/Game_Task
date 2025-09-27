#pragma once
#include "Effect.h"


class StoneSkinEffect : public Effect
{
public:
	Damage TotalDamage(Damage baseDamage, const Character* attacker, const Character* target, int turnNumber) const override;
	Damage TotalDefense(Damage incomingDamage, const Character* defender, const Character* attacker, int turnNumber) const override;
};