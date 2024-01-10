#include "Point.hpp"

Point::Point()
: x(0)
, y(0)
{};
Point::Point(const float a, const float b)
: x(a)
, y(b)
{};
Point::Point(const Point& rhs)
: x(rhs.x)
, y(rhs.y)
{};
Point::~Point()
{};
Fixed Point::GetX()
{
	return x;
}
Fixed Point::GetY()
{
	return y;
}
