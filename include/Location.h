#pragma once
#include <iostream>
struct Location
{
	int _row;
	int _col;
	Location(int row,int col);
	~Location();
	Location operator+(const Location& other);
	Location& operator+=(const Location& other);
	bool operator==(const Location& other) const;
	bool operator!=(const Location& other) const;

	friend std::ostream& operator<<(std::ostream& ostr, const Location& location);

};

std::ostream& operator<<(std::ostream& ostr, const Location& location);