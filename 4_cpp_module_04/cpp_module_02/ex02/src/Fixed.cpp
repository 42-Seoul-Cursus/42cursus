#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called\n";
	mRawBits = 0;
}
Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called\n";
	mRawBits = num << mFractionalBits;
}
Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called\n";
	mRawBits = roundf(num * (1 << mFractionalBits));
}
Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}
Fixed::Fixed(const Fixed& rhs)
{
	std::cout << "Copy constructor called\n";
	mRawBits = rhs.getRawBits();
}
const Fixed& Fixed::operator=(const Fixed& rhs)
{
	std::cout << "Assignation operator called\n";
	mRawBits = rhs.getRawBits();
	return *this;
}
bool Fixed::operator>(const Fixed& rhs) const
{
	if (toFloat() > rhs.toFloat())
	{
		return true;
	}
	return false;
}
bool Fixed::operator<(const Fixed& rhs) const
{
	if (toFloat() < rhs.toFloat())
	{
		return true;
	}
	return false;
}
bool Fixed::operator>=(const Fixed& rhs) const
{
	if (toFloat() >= rhs.toFloat())
	{
		return true;
	}
	return false;
}
bool Fixed::operator<=(const Fixed& rhs) const
{
	if (toFloat() <= rhs.toFloat())
	{
		return true;
	}
	return false;
}
bool Fixed::operator==(const Fixed& rhs) const
{
	if (toFloat() == rhs.toFloat())
	{
		return true;
	}
	return false;
}
bool Fixed::operator!=(const Fixed& rhs) const
{
	if (toFloat() != rhs.toFloat())
	{
		return true;
	}
	return false;
}
const Fixed Fixed::operator+(const Fixed& rhs) const
{
	float num = toFloat() + rhs.toFloat();
	Fixed res(num);
	return res;
}
const Fixed Fixed::operator-(const Fixed& rhs) const
{
	float num = toFloat() - rhs.toFloat();
	Fixed res(num);
	return res;
}
const Fixed Fixed::operator*(const Fixed& rhs) const
{
	float num = toFloat() * rhs.toFloat();
	Fixed res(num);
	return res;
}
const Fixed Fixed::operator/(const Fixed& rhs) const
{
	float num = toFloat() / rhs.toFloat();
	Fixed res(num);
	return res;
}
const Fixed& Fixed::operator++()
{
	++mRawBits;
	return *this;
}
const Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	++(this->mRawBits);
	return tmp;
}
const Fixed& Fixed::operator--()
{
	--mRawBits;
	return *this;
}
const Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	--(this->mRawBits);
	return tmp;
}
int Fixed::getRawBits(void) const
{
	return mRawBits;
}
void Fixed::setRawBits(const int rhs)
{
	mRawBits = rhs;
}
float Fixed::toFloat(void) const
{
	return (static_cast<float>(mRawBits) / (1 << mFractionalBits));
}
int Fixed::toInt(void) const
{
	return mRawBits >> mFractionalBits;
}
const Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	if (a.toFloat() >= b.toFloat())
	{
		return a;
	}
	return b;
}
const Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a.toFloat() >= b.toFloat())
	{
		return a;
	}
	return b;
}
const Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	if (a.toFloat() >= b.toFloat())
	{
		return b;
	}
	return a;
}
const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a.toFloat() >= b.toFloat())
	{
		return b;
	}
	return a;
}
std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return os;
}
