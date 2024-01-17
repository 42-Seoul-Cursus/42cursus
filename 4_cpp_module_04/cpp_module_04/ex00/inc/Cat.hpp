#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
private:
	Cat(const Cat& rhs);
	const Cat& operator=(const Cat& rhs);
public:
	Cat();
	~Cat();
	void	makeSound() const;
};

#endif 
