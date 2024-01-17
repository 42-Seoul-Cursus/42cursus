#include "iostream"
#include "Animal.hpp"

Animal::Animal() 
: mType("Default")
{
	std::cout << "Animal is created" << std::endl;
}
Animal::Animal(const std::string& type)
: mType(type)
{
	std::cout << "Animal is created" << std::endl;
}
Animal::~Animal() 
{
	std::cout << "Animal is destroyed" << std::endl;
}
Animal::Animal(const Animal& rhs) 
: mType(rhs.mType)
{
	std::cout << "Animal is created as a copy" << std::endl;
}
const Animal& Animal::operator=(const Animal& rhs)
{
	mType = rhs.mType;
	std::cout << "Animal is copied" << std::endl;
	return *this;
}
void Animal::makeSound() const
{
	std::cout << "Animal sound" << std::endl;
}
const std::string& Animal::GetType() const
{
	return mType;
}
void Animal::SetType(const std::string& type)
{
	mType = type;
}
