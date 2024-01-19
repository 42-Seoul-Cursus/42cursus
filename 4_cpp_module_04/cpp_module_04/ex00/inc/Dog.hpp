#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
public:
	Dog();
	~Dog();
	Dog(const Dog& rhs);
	const Dog&		operator=(const Dog& rhs);
	virtual void	MakeSound() const;
};

#endif 
