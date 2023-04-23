#include "..\include\Shark.h"

Shark::Shark(const std::string& name, const Location& location):Animal(name,location)
{}

Shark::~Shark()
{
}

void Shark::step()
{
	if (!_moving) {
		return;
	}
	int newRowLocation = _location._row + (_rowDirection * 5);
	int newColLocation = _location._col + (_colDirection * 5);
	if (newRowLocation < 0 || newRowLocation > 19 || newColLocation < 0 || newColLocation > 39) {
		_rowDirection = _rowDirection * -1;
		_colDirection = _colDirection * -1;
	}
	setLocation(newRowLocation, newColLocation);
}

char Shark::getInitial() const
{
	return 'S';
}

void Shark::move()
{
	_moving = true;
	setRandomDirections();
}

