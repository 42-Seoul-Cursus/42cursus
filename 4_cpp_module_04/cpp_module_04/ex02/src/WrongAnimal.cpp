#include "iostream"
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() 
: mType("Default")
{
	std::cout << "WrongAnimal is created" << std::endl;
}
WrongAnimal::WrongAnimal(const std::string& type)
: mType(type)
{
	std::cout << "WrongAnimal is created" << std::endl;
}
WrongAnimal::~WrongAnimal() 
{
	std::cout << "WrongAnimal is destroyed" << std::endl;
}
WrongAnimal::WrongAnimal(const WrongAnimal& rhs) 
: mType(rhs.mType)
{
	std::cout << "WrongAnimal is created as a copy" << std::endl;
}
const WrongAnimal& WrongAnimal::operator=(const WrongAnimal& rhs)
{
	mType = rhs.mType;
	std::cout << "WrongAnimal is copied" << std::endl;
	return *this;
}
void WrongAnimal::MakeSound() const
{
	std::cout << "\033[3;35m"
	<< "WrongAnimal Sound"
	<< "\033[0m" << std::endl;
}
const std::string& WrongAnimal::GetType() const
{
	return mType;
}
