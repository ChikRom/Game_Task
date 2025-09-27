#include "BattleSystem.h"
#include "Input_Output_System.h"
#include <iostream>

// Calculate the first attacker in battle with help of agility
bool BattleSystem::DetermineFirstAttacker(const Character& character, const Monster& enemy) const
{
	if (character.getAgility() > enemy.getAgility())
	{
		std::cout << "Ловкость Персонажа -> " << character.getAgility() << " больше ловкости Монстра -> "<< enemy.getAgility()<<" , Персонаж ходит первым" << std::endl;
		return 1;
	}
	else if (character.getAgility() < enemy.getAgility())
	{
		std::cout << "Ловкость Монстра -> " << enemy.getAgility() << " больше ловкости Персонажа -> " << character.getAgility() << " , Монстр ходит первым" << std::endl;
		return 0;
	}
	else
	{
		std::cout << "Ловкости Персонажа и Монстра -> " << enemy.getAgility() << " - одинаковы, " << "Персонаж ходит первым" << std::endl;
		return 1;
	}
}


// Calculate the chance of hits or misses with random agility
bool BattleSystem::CalculateHitChance(const Character& attacker, const Character& target) const
{
	int totalAgility = attacker.getAgility() + target.getAgility();
	int roll = (rand() % totalAgility) + 1;
	std::cout << "Случайная ловкость -> " << roll << " | Ловкость цели -> " << target.getAgility() << std::endl;
	if (roll <= target.getAgility())
	{
		std::cout << "Атака <<" << attacker.getName() << ">> по цели <<" << target.getName() << ">> промахнулась" << std::endl;
		return 0;
	}
	else
	{
		std::cout << "Атака <<" << attacker.getName() << ">> по цели <<" << target.getName() << ">> попала" << std::endl;
		return 1;
	}

}

// Perform one attack in the battle
bool BattleSystem::ExecuteAttack(Character& attacker, Character& target, int turnNumber)
{
	if (CalculateHitChance(attacker, target) == 0) return target.isAlive();
	Damage incomingDamage = attacker.calculateDamage(&target,turnNumber);
	std::cout << "Базовый урон атакующего  " << attacker.getName() << " -> " << attacker.baseDamage() << std::endl;
	std::cout << "Урон атакующего по цели после применения бонусов атакующего -> " << incomingDamage << std::endl;
	incomingDamage = target.calculateDefense(incomingDamage, &attacker, turnNumber);

	if (incomingDamage == 0 && attacker.calculateDefense(target.calculateDamage(&attacker,turnNumber),&target,turnNumber) == 0) // Case where both characters 
	{																															// have zero damage to each other
		system("cls");																											// It might be Barbarian vs Golem	  
		std::cout << "ПОБЕДИЛА ДРУЖБА!!! ПАРАПАРАПАМ ПАРАМ! (ПЕРСОНАЖИ НЕ МОГУТ НАНЕСТИ УРОН ДРУГ ДРУГУ)" << std::endl;
		exit(0);
	}	


	std::cout << "Урон атакующего по цели после применения бонусов цели -> " << incomingDamage << std::endl;
	std::cout << "Здоровье цели -> " << target.getCurrentHp() << std::endl;
	target.takeDamage(incomingDamage);
	std::cout << "Оставшееся здоровье цели -> " << target.getCurrentHp() << std::endl;
	return target.isAlive();


}

// Perform one battle until someone will die
bool BattleSystem::OneBattle(Character& character, Monster& enemy)
{
	ContinueInput();
	std::string check_str = character.getName();
	std::cout << "\nДА НАЧНЁТСЯ БОЙ!" << std::endl;
	bool first = DetermineFirstAttacker(character, enemy);
	int turnNumber = 1;
	Character& currentAttacker = (first) ? character : enemy;
	Character & currentDefender = (first) ? enemy : character;
	while (currentAttacker.isAlive() && currentDefender.isAlive())
	{
		ContinueInput();
		std::cout << "\n--- Ход " << turnNumber << " ---\n";
		bool defenderAlive = ExecuteAttack(currentAttacker, currentDefender, turnNumber);
		if (defenderAlive)
		{
			std::cout << currentDefender.getName() << " остался жив!" << std::endl;
			std::swap(currentAttacker, currentDefender); // if defender isAlive, swap the attacker and defender
			turnNumber++;
		}
		else
		{
			std::cout << currentDefender.getName() << " мёртв!" << std::endl;
			std::cout << currentAttacker.getName() << " ОДЕРЖАЛ ПОБЕДУ!" << std::endl;
			break;
		}
	}
	if (character.getName() != check_str)
		character = std::move(enemy);
	return character.isAlive(); // return 0 if our character died
}
