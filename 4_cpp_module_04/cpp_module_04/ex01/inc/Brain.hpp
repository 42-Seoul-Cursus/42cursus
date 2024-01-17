#ifndef BRAIN_HPP
#define BRAIN_HPP

#include "Animal.hpp"

class Brain : public Animal
{
private:
	std::string mIdeas[100];
	size_t mIdx;
public:
	Brain();
	~Brain();
	Brain(const Brain& rhs);
	const Brain& operator=(const Brain& rhs);
	void	AddIdea(const std::string& idea);
	void	PrintAllIdeas(void) const;
};

#endif 
