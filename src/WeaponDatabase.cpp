#include "WeaponDatabase.h"
#include <cassert>


// find the the weapon by name
Weapon& WeaponDatabase::getWeapon(const std::string& name)
{
	auto iter = WeaponDatabase::weapons.find(name);
	if (iter != WeaponDatabase::weapons.end())
	{
		return iter->second;
	}
	else
	{
		assert(false && "Weapon not found in database. Check spelling or add it to WeaponDatabase.");
	}
}


// map with weapons
std::map<std::string, Weapon> WeaponDatabase::weapons{
	{"Меч",{"Меч",3,DamageType::Slashing}},
	{"Дубина",{"Дубина",3,DamageType::Crushing}},
	{"Кинжал",{"Кинжал",2,DamageType::Piercing}},
	{"Топор",{"Топор",4,DamageType::Slashing}},
	{"Копьё",{"Копьё",3,DamageType::Piercing}},
	{"Легендарный Меч",{"Легендарный Меч",10,DamageType::Slashing}}

};