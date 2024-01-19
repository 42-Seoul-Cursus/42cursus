#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
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
