#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
public:
	Cat();
	~Cat();
	Cat(const Cat& rhs);
	const Cat&		operator=(const Cat& rhs);
	virtual void	MakeSound() const;
};

#endif 
