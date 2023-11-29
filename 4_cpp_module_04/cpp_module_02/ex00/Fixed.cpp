#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called\n";
	mRawBits = 0;
}
Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}
Fixed::Fixed(const Fixed& oldFixed)
{
	std::cout << "Copy constructor called\n";
	mRawBits = oldFixed.getRawBits();
}
Fixed& Fixed::operator=(const Fixed& oldFixed)
{
	std::cout << "Assignation operator called\n";
	mRawBits = oldFixed.getRawBits();
	return *this;
}
int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return mRawBits;
}
void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called\n";
	mRawBits = raw;
}
