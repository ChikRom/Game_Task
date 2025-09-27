#include <Input_Output_System.h>
#include <iostream>


// Title
void StartNewGame()
{
	std::cout << "Компьютерная Игра: ОХОТА НА РАНДОМНЫХ МОНСТРОВ" << std::endl;
	std::cout << "ХОТИТЕ СЫГРАТЬ?	Нажмите y, если хотите | Нажмите n, если не хотите: ";
}


// Offer to user to play
bool BeginInput()
{
	std::string choice;
	std::cin >> choice;
	while (choice != "y" && choice != "n")
	{
		std::cout << "Некорректный ввод, попробуйте ещё раз! ";
		std::cout << "\033[F";
		std::cout << "\033[K";
		std::cout << "ХОТИТЕ СЫГРАТЬ?	Нажмите y, если хотите | Нажмите n, если не хотите: ";
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> choice;
	}
	std::cout << "\033[F";
	std::cout << "\033[K";
	if (choice == "n")
	{
		std::cout << "ВОЗВРАЩАЙТЕСЬ СКОРЕЕ!";
		return 0;
	}
	return 1;
}

// End of the game
bool EndInput(bool winner)
{
	if (winner)
	{
		std::cout << "\nПОЗДРАВЛЯЕМ, ВЫ ПРОШЛИ ИГРУ!!!" << std::endl;
	}
	else
	{
		std::cout << "\nВЫ ПРОИГРАЛИ!!! ПОВЕЗЁТ В СЛЕДУЮЩИЙ РАЗ!" << std::endl;
	}
	std::string comm;
	std::cout << "\nНажмите y, чтобы запустить игру заново и n, чтобы выйти из игры: ";
	std::cin >> comm;
	while (comm != "y" && comm != "n")
	{
		std::cout << "Некорректный ввод, попробуйте ещё раз: ";
		std::cout << "\033[F";
		std::cout << "\033[K";
		std::cout << "Нажмите y, чтобы запустить игру заново и n, чтобы выйти из игры: ";
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> comm;
	}
	if (comm == "n")
	{
		system("cls");
		std::cout << "ВОЗВРАЩАЙТЕСЬ СКОРЕЕ!";
		return 0;
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	system("cls");
	return 1;
}

// Choose the name of character
std::string NameCharacterInput()
{
	std::string choice;
	std::cout << "Выберите нового персонажа: 1 - Разбойник, 2 - Воин, 3 - Варвар: ";
	std::cin >> choice;
	while (choice != "1" && choice != "2" && choice != "3")
	{
		std::cout << "Некорректный ввод, попробуйте ещё раз: ";
		std::cout << "\033[F";
		std::cout << "\033[K";
		std::cout << "Выберите нового персонажа: 1 - Разбойник, 2 - Воин, 3 - Варвар: ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> choice;

	}
	std::cout << "\033[K";
	std::string nameOfCharacter;
	if (choice == "1")
	{
		nameOfCharacter = "Разбойник";
	}
	else if (choice == "2")
	{
		nameOfCharacter = "Воин";
	}
	else if (choice == "3")
	{
		nameOfCharacter = "Варвар";
	}
	return nameOfCharacter;
}



// Choose the new class level of character
std::string NewLevelInput()
{
	std::string choice;
	std::cout << "\nВыберите класс персонажа, уровень которого хотите увеличить: 1 - Разбойник, 2 - Воин, 3 - Варвар: ";
	std::cin >> choice;
	while ((choice != "1" && choice != "2" && choice != "3"))
	{
		std::cout << "Некорректный ввод. Попробуйте ещё раз";
		std::cout << "\033[F";
		std::cout << "\033[K";
		std::cout << "Выберите класс персонажа, уровень которого хотите увеличить: 1 - Разбойник, 2 - Воин, 3 - Варвар: ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> choice;
	}
	std::cout << "\033[K";
	return choice;
}

void ChooseNameCharacter(std::string choice, std::string& nameOfCharacter)
{
	if (choice == "1")
	{
		nameOfCharacter = "Разбойник";
	}
	else if (choice == "2")
	{
		nameOfCharacter = "Воин";
	}
	else if (choice == "3")
	{
		nameOfCharacter = "Варвар";
	}
}

// Information about character and enemy
void OutputInfo(const Character& character, const Monster& enemy, std::string CharacterWeaponType, std::string MonsterWeaponType)
{
	std::cout << std::endl;
	std::cout << std::left;

	int col_width = 40;

	std::cout << std::setw(col_width) << "Ваш Персонаж: " + character.getName()
		<< "|	Ваш противник: " << enemy.getName() << std::endl;

	std::cout << std::setw(col_width) << "Его атрибуты и характеристики:"
		<< "|	Его атрибуты и характеристики: " << std::endl;

	std::cout << std::setw(col_width) << "Сила -> " + std::to_string(character.getStrength())
		<< "|	Сила -> " << enemy.getStrength() << std::endl;

	std::cout << std::setw(col_width) << "Ловкость -> " + std::to_string(character.getAgility())
		<< "|	Ловкость -> " << enemy.getAgility() << std::endl;

	std::cout << std::setw(col_width) << "Выносливость -> " + std::to_string(character.getEndurance())
		<< "|	Выносливость -> " << enemy.getEndurance() << std::endl;

	std::cout << std::setw(col_width) << "Здоровье -> " + std::to_string(character.getMaxHealth())
		<< "|	Здоровье -> " << enemy.getMaxHealth() << std::endl;

	std::cout << std::setw(col_width) << "Оружие -> " + character.getWeapon()->name
		<< "|	Оружие -> " << enemy.getWeaponName() << std::endl;

	std::cout << std::setw(col_width) << "Тип оружия -> " + CharacterWeaponType
		<< "|	Тип оружия -> " << MonsterWeaponType << std::endl;

	std::cout << std::setw(col_width) << "Урон оружия -> " + std::to_string(character.getWeapon()->damage)
		<< "|	Урон монстра -> " << enemy.getWeaponDamage() << std::endl;

	std::cout << std::setw(col_width) << "Изначальный урон -> " + std::to_string(character.baseDamage())
		<< "|	Изначальный урон -> " << enemy.baseDamage() << std::endl;
}


// Input for continuation in battles
void ContinueInput()
{
	std::string command;
	std::cout << "\nНажмите y, чтобы продолжить: ";
	std::cin >> command;
	while (command != "y")
	{

		std::cout << "Некорректный ввод. Попробуйте ещё раз";
		std::cout << "\033[F";
		std::cout << "\033[K";
		std::cout << "Нажмите y, чтобы продолжить: ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> command;
	}
	std::cout << "\033[K";
}


// User choose the weapon
std::string ChangeWeaponInput(Character& character, const Monster& enemy, const std::string& enemyWeapon)
{
	std::string command;
	std::cout << "\nВам доступно новое оружие за победу на соперником -> " << enemyWeapon << std::endl;
	std::cout << "Хотите заменить текущее оружие " << character.getWeapon()->name << " с уроном -> " << character.getWeapon()->damage <<
		" на новое \nоружие  " << enemyWeapon << " с уроном -> " << WeaponDatabase::getWeapon(enemyWeapon).damage << " ?";
	std::cout << "\n\nНажмите y, если хотите заменить оружие | Нажмите n, если хотите оставить текущее оружие: ";
	std::cin >> command;
	while (command != "y" && command != "n")
	{
		std::cout << "Некорректный символ, попробуйте ещё раз!";
		std::cout << "\033[F";
		std::cout << "\033[K";
		std::cout << "Нажмите y, если хотите заменить оружие | Нажмите n, если хотите оставить текущее оружие: ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> command;
	}
	return command;
}

