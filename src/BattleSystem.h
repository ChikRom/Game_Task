#pragma once
#include "Character.h"
#include "Monster.h"


// Class which manage the battle
class BattleSystem
{
public:
	bool DetermineFirstAttacker(const Character& character, const Monster& enemy) const;

	bool CalculateHitChance(const Character& attacker, const Character& target) const;

	bool ExecuteAttack(Character& attacker, Character& target, int turnNumber);

	bool OneBattle(Character& character, Monster& enemy);
};
