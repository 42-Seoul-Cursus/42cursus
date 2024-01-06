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
	Fixed(const Fixed& oldFixed);
	const Fixed&	operator=(const Fixed& c);
	const int&		getRawBits(void) const;
	void			setRawBits(const int raw);
	float			toFloat(void) const;
	int				toInt(void) const;

};
