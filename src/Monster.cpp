#include "Monster.h"
#include "SkeletonEffect.h"
#include "SlimeEffect.h"
#include "StealthAttackEffect.h"
#include "StoneSkinEffect.h"
#include "DragonEffect.h"
#include <cstdlib>
#include <iostream>


Monster::Monster()
{

}
Monster::Monster(std::string name,Attribute Strength, Attribute Agility, Attribute Endurance, Health BaseHp,std::string WeaponName, Damage BaseDamage)
	: Character(name,Strength, Agility, Endurance, BaseHp,nullptr,BaseDamage),weaponReward(WeaponName)
{
}




Damage Monster::getWeaponDamage() const
{
	return weaponDamage;
}



// Create our monsters and add them their bonuses
Monster Monster::createGoblin()
{
	return Monster("Гоблин", 1, 1, 1, 5, "Кинжал", 2);

}


Monster Monster::createSkeleton()
{
	Monster object = Monster("Скелет",2, 2, 1, 10, "Дубина",2);
	object.addEffect(std::make_unique<SkeletonEffect>());
	return std::move(object);
}

Monster Monster::createSlime()
{
	Monster object = Monster("Слайм",3, 1, 2, 8, "Копьё",1);
	object.addEffect(std::make_unique<SlimeEffect>());
	return std::move(object);
}

Monster Monster::createGhost()
{
	Monster object = Monster("Призрак",1, 3, 1, 6, "Меч",3);
	object.addEffect(std::make_unique<StealthAttackEffect>());
	return std::move(object);
}

Monster Monster::createGolem()
{
	Monster object = Monster("Голем",3, 1, 3, 10, "Топор",1);
	object.addEffect(std::make_unique<StoneSkinEffect>());
	return std::move(object);
}

Monster Monster::createDragon()
{
	Monster object = Monster("Дракон",3, 3, 3, 20, "Легендарный Меч",4);
	object.addEffect(std::make_unique< DragonEffect>());
	return std::move(object);
}

// Create enemy  from monsters
Monster Monster::createRandomMonster()
{
	unsigned short random = (rand() % 6) + 1;
	switch (random)
	{
	case 1: return createGoblin();
	case 2: return createSkeleton();
	case 3: return createSlime();
	case 4: return createGhost();
	case 5: return createGolem();
	case 6: return createDragon();
	
	}
	std::cout << "random is uncorrect";
	return createGoblin();
}


// return the reward for killing monster
std::string Monster::getWeaponName() const
{
	return weaponReward;
}