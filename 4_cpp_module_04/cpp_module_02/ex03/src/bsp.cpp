#include "Point.hpp"

static Fixed GetArea(Point const a, Point const b, Point const c)
{
	return (((a.GetX() * b.GetY()) + (b.GetX() * c.GetY()) + (c.GetX() * a.GetY()))
		 - ((b.GetX() * a.GetY()) + (c.GetX() * b.GetY()) + (a.GetX() * c.GetY()))) / 2;
}

//TODO: 신발끈 공식 벡터 외적 이용해서 정리하기..
bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed totalArea = GetArea(a, b, c);
	Fixed aArea = GetArea(a, b, point);
	Fixed bArea = GetArea(b, c, point);
	Fixed cArea = GetArea(c, a, point);
	
	if (totalArea <= aArea + bArea + cArea)
	{
		return true;
	}
	return false;
}
