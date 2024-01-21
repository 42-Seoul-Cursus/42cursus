#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Form;

class Bureaucrat
{
private:
	const std::string mName;
	int mGrade;
	const Bureaucrat& operator=(const Bureaucrat& rhs);
public:
	Bureaucrat();
	Bureaucrat(const std::string& name);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat& rhs);
	const std::string&	GetName() const;
	int					GetGrade() const;
	void				Increment(const int amount);
	void				Decrement(const int amount);
	void				SignForm(Form& form);
	class GradeTooHighException : public std::exception
	{
		virtual const char* what() const _NOEXCEPT
		{
			return "Bureaucrat : Grade is too high !";
		}
	};
	class GradeTooLowException : public std::exception
	{
		virtual const char* what() const _NOEXCEPT
		{
			return "Bureaucrat : Grade is too low !";
		}
	};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif 
