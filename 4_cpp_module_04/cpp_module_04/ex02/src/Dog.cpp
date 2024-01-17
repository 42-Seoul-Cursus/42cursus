#include <iostream>
#include "Dog.hpp"

Dog::Dog()
: AAnimal("Dog")
{
	mBrain = new Brain();
	std::cout << "Dog is created" << std::endl;
}
Dog::~Dog()
{
	delete mBrain;
	std::cout << "Dog is destroyed" << std::endl;
}
Dog::Dog(const Dog& rhs)
: AAnimal("Dog")
{
	mBrain = new Brain(*(rhs.mBrain));
	std::cout << "Dog is created as a copy" << std::endl;
}
const Dog& Dog::operator=(const Dog& rhs)
{
	*mBrain = *(rhs.mBrain);
	std::cout << "Dog is copied" << std::endl;
	return *this;
}
void Dog::makeSound() const
{
	std::cout << "bark" << std::endl;
}
void Dog::AddIdea(const std::string& idea)
{
	mBrain->AddIdea(idea);
}
void Dog::PrintAllIdeas(void) const
{
	mBrain->PrintAllIdeas();
}
