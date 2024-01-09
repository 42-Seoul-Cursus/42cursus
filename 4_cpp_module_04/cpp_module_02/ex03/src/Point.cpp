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
	x = rhs.x;
	y = rhs.y;
	return *this
};
const Point& Point::operator=(const Point& rhs)
{
	x.setRawBits(rhs.x.getRawBits());
	y.setRawBits(rhs.y.getRawBits());
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
