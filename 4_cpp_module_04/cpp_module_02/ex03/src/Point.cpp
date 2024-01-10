#include "Point.hpp"

Point::Point()
: x(0)
, y(0)
{};
Point::Point(const float a, const float b)
: x(a)
, y(b)
{};
Point::~Point()
{};
Point::Point(const Point& rhs)
{
	*this = rhs;
};
const Point& Point::operator=(const Point& rhs)
{
	const_cast<Fixed *>(&x)->setRawBits(rhs.x.getRawBits());
	const_cast<Fixed *>(&y)->setRawBits(rhs.y.getRawBits());
	return *this;
};
const Fixed& Point::GetX()
{
	return x;
}
const Fixed& Point::GetY()
{
	return y;
}
void Point::SetX(const Fixed& rhs)
{
	x = rhs;
}
void Point::SetY(const Fixed& rhs)
{
	y = rhs
}
