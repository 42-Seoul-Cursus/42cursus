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
	void				MakeSound() const;
	const std::string&	GetType() const;
};

#endif 
