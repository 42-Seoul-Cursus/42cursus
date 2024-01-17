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
void Dog::makeSound() const
{
	std::cout << "bark" << std::endl;
}
