#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int mRawBits;
	static const int mFractionalBits = 8;
public:
	Fixed();
	Fixed(const int num);
	Fixed(const float num);
	~Fixed();
	Fixed(const Fixed& rhs);
	const Fixed&	operator=(const Fixed& rhs);
	int				getRawBits(void) const;
	void			setRawBits(const int rhs);
	float			toFloat(void) const;
	int				toInt(void) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif 
