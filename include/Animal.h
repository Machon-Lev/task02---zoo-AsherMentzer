#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include "Location.h"

class Animal
{
public:
	Animal(const std::string& name,const Location& location);
	~Animal();
	void printDetails()const;
	virtual char getInitial() const = 0;
	std::string getName() const;
	Location getLocation() const;
	virtual void step() = 0;
	void stop();
	virtual void move();
	void turnVertically();
	void turnHorizontally();
protected:
	void setLocation(int row, int col);
	virtual void setRandomDirections();
	const std::string _name;
	Location _location;
	bool _moving;
	int _rowDirection;
	int _colDirection;
};


#endif // !ANIMAL_H

