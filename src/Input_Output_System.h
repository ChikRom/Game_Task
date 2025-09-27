#pragma once
#include "Character.h"
#include "Monster.h"
#include <string>
#include <iomanip>
#include <WeaponDatabase.h>


// Input and Output system functions
void StartNewGame();
bool BeginInput();
bool EndInput(bool winner);
std::string NameCharacterInput();
std::string NewLevelInput();
void ChooseNameCharacter(std::string choice, std::string& nameOfCharacter);
void OutputInfo(const Character& character, const Monster& enemy, std::string CharacterWeaponType, std::string MonsterWeaponType);
void ContinueInput();
std::string ChangeWeaponInput(Character& character, const Monster& enemy, const std::string& enemyWeapon);