#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal
{
protected:
	std::string mType;
public:
	Animal();
	Animal(const std::string& type);
	virtual ~Animal();
	Animal(const Animal& rhs);
	const Animal&		operator=(const Animal& rhs);
	virtual void		makeSound() const;
	const std::string&	getType() const;
};

#endif 
