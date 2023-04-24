#include "..\include\Monkey.h"

Monkey::Monkey(const std::string& name, const Location& location):Animal(name,location)
,_stepsCounter(0), _stepsNumber(0)
{}

Monkey::~Monkey()
{
}

void Monkey::step()
{
    if (!_moving) {
        return;
    }
    if ((_stepsCounter % 5) == 0) {
        setRandomDirections();
        _stepsNumber = rand() % 2;
    }
    int newRowLocation = _location._row + (_stepsNumber * _rowDirection);
    if (newRowLocation < 0 || newRowLocation > 19) {
        turnVertically();
        newRowLocation = _location._row + (_rowDirection * _stepsNumber);
    }
    int newColLocation = _location._col + (_colDirection * _stepsNumber);
    if (newColLocation < 0 || newColLocation > 39) {
        turnHorizontally();
        newColLocation = _location._col + (_colDirection * _stepsNumber);
    }
    setLocation(newRowLocation, newColLocation);
}

char Monkey::getInitial() const
{
    return 'M';
}

void Monkey::setRandomDirections()
{
    int dir = rand() % 4;
    switch (dir)
    {
    case(0):
        _rowDirection = 0;
        _colDirection = 1;
        break;
    case(1):
        _rowDirection = 0;
        _colDirection = -1;
        break;
    case(2):
        _rowDirection = 1;
        _colDirection = 0;
        break;
    case(3):
        _rowDirection = -1;
        _colDirection = 0;
        break;
    default:
        break;
    }
}
