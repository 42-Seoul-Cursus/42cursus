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
int Fixed::getRawBits(void) const
{
	return mRawBits;
}
void Fixed::setRawBits(int const rhs)
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
std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return os;
}
