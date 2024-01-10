#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called\n";
	mRawBits = 0;
}
Fixed::Fixed(const int rawBits)
: mRawBits(rawBits << mFractionalBits)
{
	std::cout << "Int constructor called\n";
}
Fixed::Fixed(const float rawBits)
: mRawBits(static_cast<int>(roundf(rawBits * (1 << mFractionalBits))))
{
	std::cout << "Float constructor called\n";
}
Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}
Fixed::Fixed(const Fixed& rhs)
: mRawBits(rhs.mRawBits)
{
	std::cout << "Copy constructor called\n";
}
const Fixed& Fixed::operator=(const Fixed& rhs)
{
	std::cout << "Copy assignment operator called\n";
	mRawBits = rhs.mRawBits;
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
bool Fixed::operator!=(const Fixed& rhs) const
{
	if (toFloat() != rhs.toFloat())
	{
		return true;
	}
	return false;
}
Fixed Fixed::operator+(const Fixed& rhs) const
{
	Fixed res;
	res.mRawBits = getRawBits() + rhs.getRawBits();
	return res;
}
Fixed Fixed::operator-(const Fixed& rhs) const
{
	Fixed res;
	res.mRawBits = getRawBits() - rhs.getRawBits();
	return res;
}
Fixed Fixed::operator*(const Fixed& rhs) const
{
	Fixed res;
	res.mRawBits = (toFloat() * rhs.toFloat()) * (1 << mFractionalBits);
	return res;
}
Fixed Fixed::operator/(const Fixed& rhs) const
{
	Fixed res;
	res.mRawBits = (toFloat() / rhs.toFloat()) * (1 << mFractionalBits);
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
int Fixed::getRawBits(void) const
{
	return mRawBits;
}
void Fixed::setRawBits(const int rawBits)
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
	std::cout << fixed.toFloat();
	return os;
}
