#include "Point.hpp"

static Fixed GetArea(Point const a, Point const b, Point const c);

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed totalArea = GetArea(a, b, c);
	Fixed aArea = GetArea(a, b, point);
	Fixed bArea = GetArea(b, c, point);
	Fixed cArea = GetArea(c, a, point);
	
	if (totalArea == aArea + bArea + cArea)
	{
		return true;
	}
	return false;
}

static Fixed GetArea(Point const a, Point const b, Point const c)
{
	Fixed res = ((a.GetX() * b.GetY()) + (b.GetX() * c.GetY()) + (c.GetX() * a.GetY()))
		- ((b.GetX() * a.GetY()) + (c.GetX() * b.GetY()) + (a.GetX() * c.GetY()));
	if (res < 0)
	{
		res = res * -1;
	}
	return res;
}
