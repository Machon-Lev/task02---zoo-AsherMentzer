#include "..\include\Location.h"

Location::Location(int row, int col):_row(row),_col(col){}

Location::~Location()
{
}

Location Location::operator+(const Location& other)
{
	return *(new Location(this->_row + other._row, this->_col + other._col));
}

Location& Location::operator+=(const Location& other)
{
	this->_row = other._row;
	this->_col = other._col;
	return *this;
}

bool Location::operator==(const Location& other) const
{
	return this->_row == other._row && this->_col == other._col;
}

bool Location::operator!=(const Location& other) const
{
	return !(*this == other);
}

std::ostream& operator<<(std::ostream& ostr, const Location& location)
{
	ostr << "(" << location._row << ", " << location._col << ")";
	return ostr;
}
