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

    // generate a random number
    int random_num = distr(eng);
    //std::cout << random_num<< "\n";
    //srand(time(NULL));
    int x = 25;
    x = rand();
    x = x + 2;
   // std::cout << x;
    Zoo zoo;
    zoo.run();
	return 0;
}