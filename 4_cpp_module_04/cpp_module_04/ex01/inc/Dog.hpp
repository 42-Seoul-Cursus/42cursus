#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain* mBrain;
public:
	Dog();
	~Dog();
	Dog(const Dog& rhs);
	const Dog&	operator=(const Dog& rhs);
	void		MakeSound() const;
	void		AddIdea(const std::string& idea);
	void		PrintAllIdeas(void) const;
};

#endif 
