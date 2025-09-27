#pragma once
#include "Types.h"
#include <map>
#include <string>
#include "Weapon.h"
#include <vector>
#include <memory>
#include "Effect.h"

// Class character which describe our character and his facilities
class Character
{
public:
	Character();
	Character(std::string name,Attribute Strength, Attribute Agility, Attribute Endurance, Health BaseHp,Weapon* CurWeapon,Damage BaseDamage);
	Attribute getStrength() const;
	Attribute getAgility() const;
	Attribute getEndurance() const;
	std::string getName() const;
	const Weapon* getWeapon() const;
	void levelUP(const std::string& className);
	int getTotalLevel() const;
	bool isAlive() const;
	void healToFull();
	void addEffect(std::unique_ptr<Effect>effect);
	Damage baseDamage() const;
	Damage calculateDamage(const Character* target, int turnNumber) const;
	Damage calculateDefense(Damage incomingDamage, const Character* attacker, int turnNumber) const;
	Health getMaxHealth() const;
	void setCurrentHp(Health newHp);
	Health getCurrentHp() const;
	void takeDamage(Health damage);
	void setWeapon(Weapon* newWeapon);
	Health getHp() const;

private:
	std::string name; 
	Attribute strength;
	Attribute agility;
	Attribute endurance;
	Health max_hp;
	Health current_hp;
	std::map<std::string, int> multiclass; // map of bonuses
	std::vector<std::unique_ptr<Effect>> effects; // bonuses
	Weapon* weapon;
protected:
	Damage weaponDamage; // for monster class 
};
