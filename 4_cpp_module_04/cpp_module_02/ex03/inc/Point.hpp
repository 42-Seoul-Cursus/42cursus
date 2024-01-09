#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
private:
	Fixed const x;
	Fixed const y;
public:
	Point();
	Point(const float a, const float b);
	~Point();
	Point(const Point& rhs);
	const Point&	operator=(const Point& rhs);
	const Fixed&	GetX();
	const Fixed&	GetY();
	void			SetX(const Fixed& rhs);
	void			SetY(const Fixed& rhs);
};

#endif
