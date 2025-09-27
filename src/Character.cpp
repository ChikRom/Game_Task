#include "Character.h"
#include "StealthAttackEffect.h"
#include "PoisonEffect.h"
#include "ImpulseActionEffect.h"
#include "ShieldEffect.h"
#include "RageEffect.h"
#include "StoneSkinEffect.h"
#include <cstdlib>
#include "WeaponDatabase.h"
#include <iostream>

// initialize the random attributes of character
Character::Character()
	: name ("")
	, strength(rand()%3 + 1)
	, agility(rand()%3 + 1)
	, endurance(rand()%3 + 1)
	, max_hp(0)
	, current_hp(0)
	, weapon(nullptr)
{

}

// name of character
std::string Character::getName() const
{
	return name;
}

// adding a bonus to the character
void Character::addEffect(std::unique_ptr<Effect> effect)
{
	effects.push_back(std::move(effect));
}

// Max health points of character
Health Character::getMaxHealth() const
{
	return max_hp;
}

// set the new current health point
void Character::setCurrentHp(Health newHp)
{
	current_hp = newHp;
}

// current hp of character
Health Character::getCurrentHp() const
{
	return current_hp;
}

//reduce the current hp of character
void Character::takeDamage(Health damage)
{
	current_hp = (current_hp - damage > 0) ? (current_hp - damage) : (0);
}

// set the new weapon of character (when you kill the monster you can swap the weapons)
void Character::setWeapon(Weapon* newWeapon)
{
	weapon = newWeapon;
}

// current health point of character 
Health Character::getHp() const
{
	return current_hp;
}

// base damage of character or monster without bonuses
Damage Character::baseDamage() const
{
	if (weapon != nullptr)
		return weapon->damage + strength;
	
	return weaponDamage + strength;
}

// calculate the damage of character using all his bonuses
Damage Character::calculateDamage(const Character* target, int turnNumber) const
{
	Damage damage = baseDamage();
	for (const auto& eff : effects)
	{
		damage = eff->TotalDamage(damage, this, target, turnNumber);
	}
	return damage;
}

// calculate the damage that person can take using all his bonuses
Damage Character::calculateDefense(Damage incomingDamage, const Character* attacker, int turnNumber) const
{
	Damage damage = incomingDamage;
	for (const auto& eff : effects)
	{
		damage = eff->TotalDefense(damage, this, attacker, turnNumber);
	}
	return (damage>0) ? damage : 0;
}

// create a character 
Character::Character(std::string Name, Attribute Strength, Attribute Agility, Attribute Endurance, Health BaseHp,Weapon* CurWeapon,Damage BaseDamage)
	: name(Name)
	, strength(Strength)
	, agility(Agility)
	, endurance(Endurance)
	, max_hp(BaseHp + endurance)
	, current_hp(max_hp)
	, weapon(CurWeapon)
	, weaponDamage(BaseDamage)
{
}

Attribute Character::getStrength() const
{
	return strength;
}

Attribute Character::getAgility() const
{
	return agility;
}


Attribute Character::getEndurance() const
{
	return endurance;
}

const Weapon* Character::getWeapon() const
{
	return weapon;
}

// total level for debug and checking
int Character::getTotalLevel() const
{
	int total = 0;
	for (auto& element : multiclass)
	{
		total += element.second;
	}
	return total;
}

// check if character is alive
bool Character::isAlive() const
{
	return (current_hp > 0);
}


// Heal the character in the end of the battle
void Character::healToFull()
{
	current_hp = max_hp;
}



// Increase the level of character and add new bonuses and Health points
void Character::levelUP(const std::string& className)
{
	if (name.empty())
	{
		name = className;
	}


	if (weapon == nullptr)
	{
		std::string weaponName;
		if (className == "Разбойник") weaponName = "Кинжал";
		else if (className == "Воин") weaponName = "Меч";
		else if (className == "Варвар") weaponName = "Дубина";
		weapon = &WeaponDatabase::getWeapon(weaponName);
	}
	int level = ++multiclass[className];
	
	if (className == "Разбойник")
	{
		switch (level)
		{
			case 1:
			{
				effects.push_back(std::make_unique<StealthAttackEffect>());
				break;
			}
			case 2:
			{
				agility++;
				break;
			}
			case 3:
			{
				effects.push_back(std::make_unique<PoisonEffect>());
				break;
			}
		}
	}
	else if (className == "Воин")
	{
		switch (level)
		{
			case 1:
			{
				effects.push_back(std::make_unique<ImpulseActionEffect>());
				break;
			}
			case 2:
			{
				effects.push_back(std::make_unique<ShieldEffect>());
				break;
			}
			case 3:
			{
				strength++;
				break;
			}
		}
	}
	else if (className == "Варвар")
	{
		switch (level)
		{
			case 1:
			{
				effects.push_back(std::make_unique<RageEffect>());
				break;
			}
			case 2:
			{
				effects.push_back(std::make_unique<StoneSkinEffect>());
				break;
			}
			case 3:
			{
				endurance++;
				break;
			}
		}
	}
	int hpBonus = 0;
	for (const auto& element : multiclass)
	{
		if (element.first == "Разбойник") hpBonus += element.second * 4;
		else if (element.first == "Воин") hpBonus += element.second * 5;
		else if (element.first == "Варвар") hpBonus += element.second * 6;
	}
	max_hp = hpBonus + endurance;
	current_hp = max_hp;
	std::cout << "\nВы увеличили класс -> " <<className<< " своего персонажа до уровня " << level << std::endl;
}


