#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called\n";
	mRawBits = 0;
}
Fixed::Fixed(const int rawBits)
{
	std::cout << "Int constructor called\n";
	mRawBits = rawBits << mFractionalBits;
}
Fixed::Fixed(const float rawBits)
{
	std::cout << "Float constructor called\n";
	mRawBits = roundf(rawBits * (1 << mFractionalBits));
}
Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}
Fixed::Fixed(const Fixed& rhs)
{
	std::cout << "Copy constructor called\n";
	*this = rhs;
}
const Fixed& Fixed::operator=(const Fixed& rhs)
{
	std::cout << "Copy assignment operator called\n";
	mRawBits = rhs.getRawBits();
	return *this;
}
bool Fixed::operator>(const Fixed& rhs)
{
	if (getRawBits() > rhs.getRawBits())
	{
		return true;
	}
	return false;
}
bool Fixed::operator<(const Fixed& rhs)
{
	if (getRawBits() < rhs.getRawBits())
	{
		return true;
	}
	return false;
}
bool Fixed::operator>=(const Fixed& rhs)
{
	if (getRawBits() >= rhs.getRawBits())
	{
		return true;
	}
	return false;
}
bool Fixed::operator<=(const Fixed& rhs)
{
	if (getRawBits() <= rhs.getRawBits())
	{
		return true;
	}
	return false;
}
bool Fixed::operator!=(const Fixed& rhs)
{
	if (getRawBits() != rhs.getRawBits())
	{
		return true;
	}
	return false;
}
Fixed Fixed::operator+(const Fixed& rhs)
{
	Fixed res;
	res.mRawBits = getRawBits() + rhs.getRawBits();
	return res;
}
Fixed Fixed::operator-(const Fixed& rhs)
{
	Fixed res;
	res.mRawBits = getRawBits() - rhs.getRawBits();
	return res;
}
Fixed Fixed::operator*(const Fixed& rhs)
{
	Fixed res;
	res.mRawBits = getRawBits() * rhs.getRawBits();
	return res;
}
Fixed Fixed::operator/(const Fixed& rhs)
{
	Fixed res;
	res.mRawBits = getRawBits() / rhs.getRawBits();
	return res;
}
const Fixed& Fixed::operator++()
{
	++mRawBits;
	return *this;
}
Fixed Fixed::operator++(int)
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
Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	--(this->mRawBits);
	return tmp;
}
const int& Fixed::getRawBits(void) const
{
	return mRawBits;
}
void Fixed::setRawBits(int const rawBits)
{
	mRawBits = rawBits;
}
float Fixed::toFloat(void) const
{
	return (static_cast<float>(mRawBits) / static_cast<float>(1 << mFractionalBits));
}
int Fixed::toInt(void) const
{
	return mRawBits >> mFractionalBits;
}
std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	if (fixed.getRawBits() % 256 == 0)
	{
		std::cout << fixed.toInt();
	}
	else
	{
		std::cout << fixed.toFloat();
	}
	return os;
}
const Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	if (a.getRawBits() >= b.getRawBits())
	{
		return a;
	}
	return b;
}
const Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a.getRawBits() >= b.getRawBits())
	{
		return a;
	}
	return b;
}
const Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	if (a.getRawBits() >= b.getRawBits())
	{
		return b;
	}
	return a;
}
const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a.getRawBits() >= b.getRawBits())
	{
		return b;
	}
	return a;
}
