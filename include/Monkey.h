#pragma once
#include "Animal.h"

class Monkey : public Animal {
public:
	Monkey(const std::string& name, const Location& location);
	~Monkey();
	void step()override;
	char getInitial() const override;
private:
	int _stepsCounter;
	int _stepsNumber;
};