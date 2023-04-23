#pragma once
#include "Animal.h"

class Shark : public Animal
{
public:
	Shark(const std::string& name, const Location& location);
	~Shark();
	void step() override;
	char getInitial() const override;
	void move() override;
private:

};

