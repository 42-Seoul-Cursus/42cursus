#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Form
{
private:
	const std::string mName;
	bool mbIsSigned;
	const int mMinGradeForSign;
	const int mMinGradeForExecute;
	const Form& operator=(const Form& rhs);
public:
	Form(const std::string& name, int minGradeForSign, int minGradeForExecute);
	~Form();
	Form(const Form& rhs);
	const std::string&	GetName() const;
	bool				GetIsSigned() const;
	int					GetMinGradeForSign() const;
	int					GetMinGradeForExecte() const;
	void				BeSigned(const Bureaucrat& bureaucrat);
	class GradeTooHighException : public std::exception
	{
		virtual const char* what() const _NOEXCEPT
		{
			return "Form : Grade is too high !";
		}
	};
	class GradeTooLowException : public std::exception
	{
		virtual const char* what() const _NOEXCEPT
		{
			return "From : Grade is too low !";
		}
	};
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif 
