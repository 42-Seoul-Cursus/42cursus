#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
private:
	Fixed const x;
	Fixed const y;
	const Point&	operator=(const Point& rhs);
public:
	Point();
	Point(const float a, const float b);
	Point(const Point& rhs);
	~Point();
	Fixed			GetX();
	Fixed			GetY();
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif
