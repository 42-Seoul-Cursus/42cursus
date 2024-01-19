#include <iostream>
#include "Cat.hpp"

Cat::Cat()
: Animal("Cat")
{
	mBrain = new Brain();
	std::cout << "Cat is created" << std::endl;
}
Cat::~Cat()
{
	delete mBrain;
	std::cout << "Cat is destroyed" << std::endl;
}
Cat::Cat(const Cat& rhs)
: Animal(rhs.mType)
{
	mBrain = new Brain(*(rhs.mBrain));
	std::cout << "Cat is created as a copy" << std::endl;
}
const Cat& Cat::operator=(const Cat& rhs)
{
	mType = rhs.mType;
	*mBrain = *(rhs.mBrain);
	std::cout << "Cat is copied" << std::endl;
	return *this;
}
void Cat::MakeSound() const
{
	std::cout << "\033[3;37m"
	<< "🐱 meow 🐱"
	<< "\033[0m" << std::endl;
}
void Cat::AddIdea(const std::string& idea)
{
	mBrain->AddIdea(idea);
}
void Cat::PrintAllIdeas(void) const
{
	mBrain->PrintAllIdeas();
}
