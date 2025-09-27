#pragma once

#include "Weapon.h"
#include <map>

// class which store information about weapons
class WeaponDatabase
{
public:
	 static Weapon& getWeapon(const std::string& name);

private:
	static std::map<std::string, Weapon> weapons;
};