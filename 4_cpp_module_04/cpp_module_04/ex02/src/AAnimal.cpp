#include "iostream"
#include "AAnimal.hpp"

AAnimal::AAnimal() 
: mType("Default")
{
	std::cout << "AAnimal is created" << std::endl;
}
AAnimal::AAnimal(const std::string& type)
: mType(type)
{
	std::cout << "AAnimal is created" << std::endl;
}
AAnimal::~AAnimal() 
{
	std::cout << "AAnimal is destroyed" << std::endl;
}
AAnimal::AAnimal(const AAnimal& rhs) 
: mType(rhs.mType)
{
	std::cout << "AAnimal is created as a copy" << std::endl;
}
const AAnimal& AAnimal::operator=(const AAnimal& rhs)
{
	mType = rhs.mType;
	std::cout << "AAnimal is copied" << std::endl;
	return *this;
}
const std::string& AAnimal::GetType() const
{
	return mType;
}
void AAnimal::SetType(const std::string& type)
{
	mType = type;
}
