#include <iostream>
#include "WrongCat.hpp"

WrongCat::WrongCat()
: WrongAnimal("WrongCat")
{
	mBrain = new Brain();
	std::cout << "WrongCat is created" << std::endl;
}
WrongCat::~WrongCat()
{
	delete mBrain;
	std::cout << "WrongCat is destroyed" << std::endl;
}
WrongCat::WrongCat(const WrongCat& rhs)
: WrongAnimal(rhs.mType)
{
	mBrain = new Brain(*(rhs.mBrain));
	std::cout << "WrongCat is created as a copy" << std::endl;
}
const WrongCat& WrongCat::operator=(const WrongCat& rhs)
{
	mType = rhs.mType;
	*mBrain = *(rhs.mBrain);
	std::cout << "WrongCat is copied" << std::endl;
	return *this;
}
void WrongCat::MakeSound() const
{
	std::cout << "\033[3;37m"
	<< "🐱 meow 🐱"
	<< "\033[0m" << std::endl;
}
void WrongCat::AddIdea(const std::string& idea)
{
	mBrain->AddIdea(idea);
}
void WrongCat::PrintAllIdeas(void) const
{
	mBrain->PrintAllIdeas();
}
