#include "Zoo.h"
#include "Location.h"
#include "Lion.h"
#include "Monkey.h"
#include "Shark.h"
#include <random>


int main() {
    std::random_device rd;  // obtain a random seed from the hardware
    std::mt19937 eng(rd());  // seed the generator
    std::uniform_int_distribution<> distr(1, 6);  // define the range
    Zoo zoo;
    zoo.run();
	return 0;
}