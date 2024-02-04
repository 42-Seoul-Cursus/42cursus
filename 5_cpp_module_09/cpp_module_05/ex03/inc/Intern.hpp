#ifndef INTERN_HPP
#define INTERN_HPP

#include <iosfwd>

class AForm;

class Intern
{
private:
	Intern(const Intern& rhs);
	const Intern& operator=(const Intern& rhs);
public:
	Intern();
	~Intern();
	AForm*	MakeForm(const std::string& name, const std::string& target);
};

#endif 
