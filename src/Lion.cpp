#include "Lion.h"

Lion::Lion(const std::string& name, const Location& location):Animal(name,location)
{}

Lion::~Lion()
{}

char Lion::getInitial() const
{
	return 'L';
}

void Lion::move()
{
	_moving = true;
	int i = rand() % 2;
	if((i == 0)){
		//move right
		_colDirection = 1;
	}		
	else
	{
		// move left
		_colDirection = -1;
	}
}

void Lion::step()
{
	if (!_moving)
		return;
	int newColLocation = _location._col + (2 * _colDirection);
	if (newColLocation < 0 || newColLocation > 39) {
		_colDirection = _colDirection * -1;
	}
	setLocation(_location._row , newColLocation);
}