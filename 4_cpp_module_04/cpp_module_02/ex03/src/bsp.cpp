#include "Point.hpp"

static Fixed GetArea(Point& const a, Point& const b, Point& const c)
{
	return ((a.GetX() * b.GetY()) + (b.GetX() * c.GetY()) + (c.GetX() * a.GetY()))
		 - ((b.GetX() * a.GetY()) + (c.GetX() * b.GetY()) + (a.GetX() * c.GetY()));
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed area = GetArea(a, b, c);

	std::cout << area << std::endl;
	return true;
}
