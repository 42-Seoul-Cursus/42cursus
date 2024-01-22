#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	const std::string mName;
	bool mbIsSigned;
	const int mMinGradeForSign;
	const int mMinGradeForExecute;
	const PresidentialPardonForm& operator=(const PresidentialPardonForm& rhs);
public:
	PresidentialPardonForm(const std::string& name, int minGradeForSign, int minGradeForExecute);
	virtual ~PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm& rhs);
	const std::string&	GetName() const;
	bool				GetIsSigned() const;
	int					GetMinGradeForSign() const;
	int					GetMinGradeForExecte() const;
	void				BeSigned(const Bureaucrat& bureaucrat);
	class GradeTooHighException : public std::exception
	{
		virtual const char* what() const _NOEXCEPT
		{
			return "PresidentialPardonForm : Grade is too high !";
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

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& form);

#endif 
