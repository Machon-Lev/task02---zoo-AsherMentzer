#include "Animal.h"


Animal::Animal(const std::string& name, const Location& location):_name(name),_location(location)
,_moving(true),_rowDirection(0),_colDirection(0)
{}

Animal::~Animal()
{
}

void Animal::printDetails() const
{
	std::cout << _name << " " << _location << std::endl;
}

std::string Animal::getName() const
{
	return _name;
}

Location Animal::getLocation() const
{
	return _location;
}

void Animal::step()
{
}

void Animal::stop()
{
	_moving = false;
}

void Animal::move()
{
	_moving = true;
}

void Animal::turnVertically()
{
	_rowDirection = _rowDirection * -1;
}

void Animal::turnHorizontally()
{
	_colDirection = _colDirection * -1;
}

void Animal::setLocation(int row, int col)
{
	_location._row = row;
	_location._col = col;
}

void Animal::setRandomDirections()
{
	int rDir = rand() % 3;
	switch (rDir)
	{
	case(0):
		_rowDirection = 0;
		break;
	case(1):
		_rowDirection = 1;
		break;
	case(2):
		_rowDirection = -1;
		break;
	default:
		break;
	}
	int cDir = rand() % 3;
	switch (cDir)
	{
	case(0):
		_colDirection = 0;
		break;
	case(1):
		_colDirection = 1;
		break;
	case(2):
		_colDirection = -1;
		break;
	default:
		break;
	}
}

