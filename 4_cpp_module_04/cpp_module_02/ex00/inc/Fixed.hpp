#include <iostream>

class Fixed
{
private:
	int mRawBits;
	static const int mFractionalBits = 8;
public:
	Fixed();
	~Fixed();
	Fixed(const Fixed& oldFixed);
	const Fixed&	operator=(const Fixed& c);
	int				getRawBits(void) const;
	void			setRawBits(const int rhs);
};
