#include <iostream>
#include "WrongCat.hpp"

WrongCat::WrongCat()
: WrongAnimal("WrongCat")
{
	std::cout << "WrongCat is created" << std::endl;
}
WrongCat::~WrongCat()
{
	std::cout << "WrongCat is destroyed" << std::endl;
}
WrongCat::WrongCat(const WrongCat& rhs)
: WrongAnimal(rhs.mType)
{
	std::cout << "WrongCat is created as a copy" << std::endl;
}
const WrongCat& WrongCat::operator=(const WrongCat& rhs)
{
	if (this != &rhs)
	{
		mType = rhs.mType;
	}
	std::cout << "WrongCat is copied" << std::endl;
	return *this;
}
void WrongCat::MakeSound() const
{
	std::cout << "\033[3;37m"
	<< "🐱 woem 🐱"
	<< "\033[0m" << std::endl;
}
