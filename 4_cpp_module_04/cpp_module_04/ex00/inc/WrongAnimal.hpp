#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>

class WrongAnimal
{
protected:
	std::string mType;
public:
	WrongAnimal();
	WrongAnimal(const std::string& type);
	~WrongAnimal();
	WrongAnimal(const WrongAnimal& rhs);
	const WrongAnimal&	operator=(const WrongAnimal& rhs);
	void				makeSound() const;
	const std::string&	getType() const;
};

#endif 
