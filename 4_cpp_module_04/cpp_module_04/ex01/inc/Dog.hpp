#ifndef Dog_HPP
#define Dog_HPP

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
	void		makeSound() const;
	void		AddIdea(const std::string& idea);
	void		PrintAllIdeas(void) const;
};

#endif 
