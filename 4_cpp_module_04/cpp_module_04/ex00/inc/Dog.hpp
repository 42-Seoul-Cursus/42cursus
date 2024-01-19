#ifndef Dog_HPP
#define Dog_HPP

#include "Animal.hpp"

class Dog : public Animal
{
public:
	Dog();
	~Dog();
	Dog(const Dog& rhs);
	const Dog&		operator=(const Dog& rhs);
	virtual void	makeSound() const;
};

#endif 
