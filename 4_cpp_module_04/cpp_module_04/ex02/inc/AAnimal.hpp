#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <string>

class AAnimal
{
protected:
	std::string mType;
public:
	AAnimal();
	AAnimal(const std::string& type);
	virtual ~AAnimal();
	AAnimal(const AAnimal& rhs);
	const AAnimal&		operator=(const AAnimal& rhs);
	virtual void		MakeSound() const = 0;
	const std::string&	GetType() const;
};

#endif 
