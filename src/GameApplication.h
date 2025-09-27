#pragma once

#include "Monster.h"
#include "Character.h"

// Class which manage the main events in the game
class GameApplication
{
public:
	void Run();

private:
	void CreateCharacters(Character& character,Monster& monster);
	void NewLevelCharacter(Character& character);
	void ShowCharacters(const Character& character, const Monster& enemy) const;
	void OfferWeaponSwap(Character& character, const Monster& enemy);
	void GetWeaponsTypes(const Character& character, const Monster& enemy, std::string& CharacterWeaponType, std::string& MonsterWeaponType) const;
};