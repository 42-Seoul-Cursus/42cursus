#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <string>

class AAnimal
{
private:
	std::string mType;
public:
	AAnimal();
	AAnimal(const std::string& type);
	virtual ~AAnimal();
	AAnimal(const AAnimal& rhs);
	const AAnimal&		operator=(const AAnimal& rhs);
	virtual void		makeSound() const = 0;
	const std::string&	GetType() const;
	void				SetType(const std::string& type);
};

#endif 
