#pragma once
#include "Animal.h"
#include <vector>

#define X 10

enum AnimalType {
#define ANIMAL(a) E_##a
#include "AnimalTypes.h"
	E_unsupported,
	E_supported_animals_num = E_unsupported,
#undef ANIMAL(a)
};

class Zoo {

public:
	//Zoo(std::vector<std::vector<int>> zoo_map);
	void run();

private:
	const std::vector<std::string> knownAnimals = {
#define ANIMAL(a) #a
#include "AnimalTypes.h" 
#undef ANIMAL(a)
	};
	void stop(int animal_index);
	void move(int animal_index);
	void del(int animal_index);
	void delAll(AnimalType animal_type);
	void create(AnimalType animal_type, std::string name);
	void help();
	void printMenue();
	void printMap();
	void printList();
	void initZoo();
	void step();
	Location randLocation();
	AnimalType strToAnimlaType(std::string type);
	std::vector<std::unique_ptr<Animal>> animals;
	

};