#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>

class Bureaucrat
{
private:
	const std::string mName;
	int mGrade;
	const Bureaucrat& operator=(const Bureaucrat& rhs);
public:
	Bureaucrat();
	Bureaucrat(const std::string& name);
	Bureaucrat(const std::string& name, const int grade);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat& rhs);
	const std::string&	GetName() const;
	int					GetGrade() const;
};

#endif 
