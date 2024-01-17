#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal
{
private:
	std::string mType;
public:
	Animal();
	Animal(const std::string& type);
	~Animal();
	Animal(const Animal& rhs);
	const Animal&		operator=(const Animal& rhs);
	virtual void		makeSound() const;
	const std::string&	GetType() const;
	void				SetType(const std::string& type);
};

#endif 
