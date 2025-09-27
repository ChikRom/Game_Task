#include "GameApplication.h"
#include "BattleSystem.h"
#include "Input_Output_System.h"
#include <iostream>


// Game Loop
void GameApplication::Run()
{
	while (true)
	{
		StartNewGame();
		if (!BeginInput())
			return;
		int wins = 0;
		std::cout << std::endl;
		Character character;
		Monster enemy;
		CreateCharacters(character,enemy); 
		BattleSystem battle;
		int level = 1;
		while (wins < 5 && character.isAlive())
		{
			bool winner = battle.OneBattle(character, enemy);
			if (winner == 1 && wins < 4)
			{
				wins++;
				character.healToFull();
				if (level < 3)
				{
					NewLevelCharacter(character);
					level++;
				}
				else
				{
					std::cout << "\n\nВы достигли максимального уровня прокачки и больше не можете увеличивать уровень персонажа! " << std::endl;
				}
				OfferWeaponSwap(character, enemy);
				enemy = Monster::createRandomMonster();
				ShowCharacters(character, enemy);
			}
			else
			{
				if (!EndInput(winner))
					return;
				break;
				
			}
		}
	}
	
}

// Create character and enemy, show their attributes in the begin of the battle
void GameApplication::CreateCharacters(Character& character,Monster& enemy)
{
	std::string nameOfCharacter = NameCharacterInput();
	character.levelUP(nameOfCharacter);
	enemy = Monster::createRandomMonster();
	ShowCharacters(character, enemy);
	
}


// Increase the level of character
void GameApplication::NewLevelCharacter(Character& character)
{
	std::string choice = NewLevelInput();
	std::string nameOfCharacter;
	ChooseNameCharacter(choice, nameOfCharacter);
	character.levelUP(nameOfCharacter);

}

// Show attributes of character and enemy between the battles
void GameApplication::ShowCharacters(const Character& character,const Monster& enemy) const
{
	std::string CharacterWeaponType;
	std::string MonsterWeaponType;
	GetWeaponsTypes(character, enemy, CharacterWeaponType, MonsterWeaponType);
	OutputInfo(character, enemy, CharacterWeaponType, MonsterWeaponType);
}


// Event of changing the weapon
void GameApplication::OfferWeaponSwap(Character& character, const Monster& enemy)
{
	ContinueInput();
	std::string enemyWeapon = enemy.getWeaponName();
	if (ChangeWeaponInput(character,enemy,enemyWeapon) == "y")
	{
		character.setWeapon(&WeaponDatabase::getWeapon(enemyWeapon));
	}
	system("cls");
	std::cout << "Ваше текущее оружие -> " << character.getWeapon()->name << std::endl;
}

// for show attribtutes
void GameApplication::GetWeaponsTypes(const Character& character, const Monster& enemy, std::string& CharacterWeaponType, std::string& MonsterWeaponType) const
{
	switch (character.getWeapon()->type)
	{
		case DamageType::Slashing:
		{
			CharacterWeaponType = "Рубящее";
			break;
		}
		case DamageType::Crushing:
		{
			CharacterWeaponType = "Дробящее";
			break;
		}
		case DamageType::Piercing:
		{
			CharacterWeaponType = "Колющее";
			break;
		}
	}

	switch (WeaponDatabase::getWeapon(enemy.getWeaponName()).type)
	{
		case DamageType::Slashing:
		{
			MonsterWeaponType = "Рубящее";
			break;
		}
		case DamageType::Crushing:
		{
			MonsterWeaponType = "Дробящее";
			break;
		}
		case DamageType::Piercing:
		{
			MonsterWeaponType = "Колющее";
		}
	}

}






