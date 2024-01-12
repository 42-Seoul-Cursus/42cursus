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
	std::cout << "getRawBits member function called\n";
	return mRawBits;
}
void Fixed::setRawBits(const int rhs)
{
	std::cout << "setRawBits member function called\n";
	mRawBits = rhs;
}
