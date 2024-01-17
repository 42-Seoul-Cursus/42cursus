#include <iostream>
#include "Cat.hpp"

Cat::Cat()
: Animal("Cat")
{
	std::cout << "Cat is created" << std::endl;
}
Cat::~Cat()
{
	std::cout << "Cat is destroyed" << std::endl;
}
void Cat::makeSound() const
{
	std::cout << "meow" << std::endl;
}
