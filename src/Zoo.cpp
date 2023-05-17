#include "..\include\Zoo.h"
#include "Lion.h"
#include "Monkey.h"
#include "Shark.h"


void Zoo::run()
{
	int index;
	initZoo();
	std::string type;
	std::string name;
	bool validCommand;

	std::string userInput = "";
	while (!(userInput == "exit")) {
		printMap();
		printList();
		printMenue();
		std::cin >> userInput;
		std::cout << "you entered:  " << userInput << std::endl;
		validCommand = true;
		if (userInput == "stop")
		{
			std::cout << "enter the animal index:" << "\n";
			std::cin >> index;
			stop(index);
			std::cout << "stoped" << "\n";
		}
		else if (userInput == "create")
		{
			std::cout << "enter type" << "\n";
			std::cin >> type;
			std::cout << "enter name" << "\n";
			std::string animalName = "";
			std::cin >> animalName;
			create(strToAnimlaType(type), animalName);
			std::cout << type << " created" << "\n";
		}
		else if (userInput == "move")
		{
			std::cout << "enter the animal index" << "\n";
			std::cin >> index;
			move(index);
			std::cout << "moved" << "\n";
		}
		else if (userInput == "del")
		{
			std::cout << "enter the animal index" << "\n";
			std::cin >> index;
			del(index);
			std::cout << "deleted" << "\n";
		}
		else if (userInput == "delAll")
		{
			std::cout << "enter the animal type" << "\n";
			std::cin >> type;
			delAll(strToAnimlaType(type));
			std::cout << "all "<< type << " deleted" << "\n";
		}
		else if (userInput == "help")
		{
			help();
		}
		// '.' means to advance turn, which happens anyway with every legal command
		// so no action needs to be taken now.
		else if (userInput == ".") {
		}
		else
		{
			validCommand = false;
			std::cout << "unsupported command\n";
			continue;
		}
		// Do not advance turn untill getting valid command
	
		step();
		//printMap();
		//printList();
		//printMenue();
	}
}

void Zoo::stop(int animal_index)
{
	animals[animal_index]->stop();
}

void Zoo::move(int animal_index)
{
	animals[animal_index]->move();
}

void Zoo::del(int animal_index)
{
	animals.erase(animals.begin() + animal_index);
}

void Zoo::delAll(AnimalType animal_type)
{
	char fLetter;
	switch (animal_type)
	{
	case E_lion:
		fLetter = 'L';
		break;
	case E_monkey:
		fLetter = 'M';
		break;
	case E_shark:
		fLetter = 'S';
		break;
	default:
		break;
	}
	animals.erase(std::remove_if(
		animals.begin(), animals.end(),
		[fLetter](const std::unique_ptr<Animal>& animal) {
			return animal->getInitial() == fLetter;
		}), animals.end());
}

void Zoo::create(AnimalType animal_type, std::string name)
{
	std::string type;
	switch (animal_type)
	{
	case(E_lion):
		animals.push_back(std::make_unique<Lion>(name, randLocation()));
		break;
	case(E_monkey):
		animals.push_back(std::make_unique<Monkey>(name, randLocation()));
		break;
	case(E_shark):
		animals.push_back(std::make_unique<Shark>(name, randLocation()));
		break;

	default:
		break;
	}
	animals[animals.size() - 1]->move();
}

void Zoo::help()
{
	std::string helper = "";
	helper += "1. stop -> make the animal to stop, get as parameter the animal number in the list\n";
	helper += "2. move -> make the animal to move, get as parameter the animal number in the list\n";
	helper += "3. create -> add new animal to the zoo, get as parameters the animal type and the animal name\n";
	helper += "4. del -> delete animal from the zoo, get as parameter the animal number in the list\n";
	helper += "5. delAll -> delete all the animals of this type from the zoo, get as parameter the animals type\n";
	helper += "6. help -> print the command and explanation\n";
	helper += "7. exit -> exit the program\n";
	helper += "8. dot -> continue to next step\n";
	std::cout<< helper;
}


void Zoo::printMenue()
{
	std::string instructions = "COMMANDS:\n";
	instructions += "1. stop \n";
	instructions += "2. move \n";
	instructions += "3. create \n";
	instructions += "4. del \n";
	instructions += "5. delAll \n";
	instructions += "6. help \n";
	instructions += "7. exit \n";
	instructions += "8. dot \n";
	std::cout << instructions;
}

void Zoo::printMap()
{
	std::cout<< "ZOO MAP:\n";
	for (int row = 0; row < 20; ++row) {
		for (int col = 0; col < 40; ++col) {
			bool animalInCell = false;
			for (auto& animal : animals) {
				if (animal->getLocation()._row == row && animal->getLocation()._col == col) {
					std::cout << animal->getInitial();
					animalInCell = true;
					break;
				}
			}
			if (!animalInCell) {
				std::cout << "-";
			}
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}

void Zoo::printList()
{
	int index = 0;
	std::cout << "ZOO LIST:\n";
	for (auto& animal : animals)
	{
		std::cout << index << ": ";
		animal->printDetails();
		index++;
	}
	std::cout << "\n";
}

void Zoo::initZoo()
{
	create(E_lion, "Simba");
	create(E_lion, "Mufasa");
	create(E_monkey, "Rafiki");
	create(E_shark, "Jaws");
}

void Zoo::step()
{
	for (auto& animal : animals) {
		animal->step();
	}
}

Location Zoo::randLocation()
{
	return Location(rand()%20, rand() % 40);
}

AnimalType Zoo::strToAnimlaType(std::string type)
{
	int i;
	for (i = 0; i < knownAnimals.size(); i++)
	{
		if (knownAnimals[i] == type)
		{
			return (AnimalType)i;
		}
	}
	return (AnimalType)i;
}
