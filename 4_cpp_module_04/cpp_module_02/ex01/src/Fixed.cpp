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
Fixed::Fixed(const Fixed& oldFixed)
{
	std::cout << "Copy constructor called\n";
	*this = oldFixed;
}
const Fixed& Fixed::operator=(const Fixed& oldFixed)
{
	std::cout << "Copy assignment operator called\n";
	mRawBits = oldFixed.getRawBits();
	return *this;
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
const int& Fixed::getRawBits(void) const
{
	return mRawBits;
}
void Fixed::setRawBits(int const raw)
{
	mRawBits = raw;
}
float Fixed::toFloat(void) const
{
	return (static_cast<float>(mRawBits) / (1 << mFractionalBits));
}
int Fixed::toInt(void) const
{
	return mRawBits >> mFractionalBits;
}
