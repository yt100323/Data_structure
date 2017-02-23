#include "Coordinate.h"
#include <iostream>

using namespace std;

ostream &operator<<(ostream &out, const Coordinate &coor)
{
	out << "(" << coor.m_iX << "," << coor.m_iY << ")";
	return out;
}

bool operator==(const Coordinate &coor1, const Coordinate &coor2)
{
	if ((coor1.m_iX == coor2.m_iX) && (coor1.m_iY == coor2.m_iY))
		return true;
	else
		return false;
}

Coordinate::Coordinate(int x, int y)
{
	m_iX = x;
	m_iY = y;
	//cout << "Coordinate() " << m_iX << " " << m_iY << endl;
}

void Coordinate::printCoordinate()
{
	cout << "(" << m_iX << "," << m_iY << ")";
}
