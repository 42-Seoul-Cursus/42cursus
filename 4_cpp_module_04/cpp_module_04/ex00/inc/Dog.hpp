#ifndef Dog_HPP
#define Dog_HPP

#include "Animal.hpp"

class Dog : public Animal
{
private:
	Dog(const Dog& rhs);
	const Dog& operator=(const Dog& rhs);
public:
	Dog();
	~Dog();
	void	makeSound() const;
};

#endif 
