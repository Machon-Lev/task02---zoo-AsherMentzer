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
        int dir = rand() %4;
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
        _stepsNumber = rand() % 2;
    }
    Location oldLocation = this->getLocation();
    int newRowLocation = oldLocation._row + (_stepsNumber * _rowDirection);
    int newColLocation = oldLocation._col + (_stepsNumber * _colDirection);
    if (newRowLocation >= 0 && newRowLocation < 20 && newColLocation >= 0 && newColLocation < 40) {
        this->setLocation(newRowLocation, newColLocation);
    }
}

char Monkey::getInitial() const
{
    return 'M';
}
