#pragma once

#include "Character.h"

// class monster, which describe our enemy
class Monster : public Character
{
public:
	Monster();
	Monster(std::string name,Attribute Strength, Attribute Agility, Attribute Endurance, Health BaseHp, std::string WeaponName, Damage BaseDamage);
	static Monster createGoblin();
	static Monster createSkeleton();
	static Monster createSlime();
	static Monster createGhost();
	static Monster createGolem();
	static Monster createDragon();
	static Monster createRandomMonster();
	std::string getWeaponName() const;
	Damage getWeaponDamage() const;

private:
	std::string weaponReward;

};