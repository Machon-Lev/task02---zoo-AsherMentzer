#pragma once
#include "Animal.h"

class Lion: public Animal
{
public:
	Lion(const std::string& name, const Location& location);
	~Lion();
	char getInitial() const override;
	void move() override;
	void step() override;
};

