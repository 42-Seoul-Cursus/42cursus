#include <iostream>
#include "Dog.hpp"

Dog::Dog()
: Animal("Dog")
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
: Animal(rhs.mType)
{
	mBrain = new Brain(*(rhs.mBrain));
	std::cout << "Dog is created as a copy" << std::endl;
}
const Dog& Dog::operator=(const Dog& rhs)
{
	if (this != &rhs)
	{
		mType = rhs.mType;
		*mBrain = *(rhs.mBrain);
	}
	std::cout << "Dog is copied" << std::endl;
	return *this;
}
void Dog::MakeSound() const
{
	std::cout << "\033[3;33m"
	<< "🐶 bark 🐶"
	<< "\033[0m" << std::endl;
}
void Dog::AddIdea(const std::string& idea)
{
	mBrain->AddIdea(idea);
}
void Dog::PrintAllIdeas(void) const
{
	mBrain->PrintAllIdeas();
}
