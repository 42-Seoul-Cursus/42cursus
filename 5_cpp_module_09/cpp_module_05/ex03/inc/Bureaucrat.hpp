#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class AForm;

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
	void				Increment(const unsigned int amount);
	void				Decrement(const unsigned int amount);
	void				SignForm(AForm& form) const;
	void				ExecuteForm(const AForm& form) const;
	class GradeTooHighException : public std::exception
	{
		virtual const char* what() const _NOEXCEPT
		{
			return "\033[0;31mGrade is too high !\033[0m";
		}
	};
	class GradeTooLowException : public std::exception
	{
		virtual const char* what() const _NOEXCEPT
		{
			return "\033[0;31mGrade is too low !\033[0m";
		}
	};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif 
