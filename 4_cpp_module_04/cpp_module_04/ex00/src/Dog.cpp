#include <iostream>
#include "Dog.hpp"

Dog::Dog()
: Animal("Dog")
{
	std::cout << "Dog is created" << std::endl;
}
Dog::~Dog()
{
	std::cout << "Dog is destroyed" << std::endl;
}
Dog::Dog(const Dog& rhs)
: Animal(rhs.mType)
{
	std::cout << "Dog is created as a copy" << std::endl;
}
const Dog& Dog::operator=(const Dog& rhs)
{
	mType = rhs.mType;
	std::cout << "Dog is copied" << std::endl;
	return *this;
}
void Dog::MakeSound() const
{
	std::cout << "\033[3;33m"
	<< "🐶 bark 🐶"
	<< "\033[0m" << std::endl;
}
