#pragma once
#include "Types.h"
#include <string>

// types of damage
enum class DamageType
{
	Slashing,
	Crushing, 
	Piercing 
};

// struct which describe weapon
struct Weapon
{
	std::string name;
	Damage damage;
	DamageType type;
};
