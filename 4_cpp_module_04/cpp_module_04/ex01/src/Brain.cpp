#include <iostream>
#include "Brain.hpp"

Brain::Brain()
: mIdx(0)
{
	std::cout << "Brain is created" << std::endl;
}
Brain::~Brain()
{
	std::cout << "Brain is destroyed" << std::endl;
}
Brain::Brain(const Brain& rhs)
{
	for (size_t i = 0; i < rhs.mIdx; i++)
	{
		mIdeas[i] = rhs.mIdeas[i];
	}
	mIdx = rhs.mIdx;
	std::cout << "Brain is created as a copy" << std::endl;
}
const Brain& Brain::operator=(const Brain& rhs)
{
	if (this != &rhs)
	{
		for (size_t i = 0; i < rhs.mIdx; i++)
		{
			mIdeas[i] = rhs.mIdeas[i];
		}
		mIdx = rhs.mIdx;
	}
	std::cout << "Brain is copied" << std::endl;
	return *this;
}
void Brain::AddIdea(const std::string& idea)
{
	if (mIdx == 100)
	{
		std::cout << "\033[0;33m"
		<< "Brain is full..."
		<< "\033[0m" << std::endl;
		return ;
	}
	mIdeas[mIdx++] = idea;
	std::cout << "\033[0;32m"
	<< "Ideas added to the brain !"
	<< "\033[0m" << std::endl;
}
void Brain::PrintAllIdeas(void) const
{
	for (size_t i = 0; i < mIdx; i++)
	{
		std::cout << "\033[3;39m" << "\033[45m"
		<< mIdeas[i] 
		<< "\033[0m" << std::endl;
	}
}
