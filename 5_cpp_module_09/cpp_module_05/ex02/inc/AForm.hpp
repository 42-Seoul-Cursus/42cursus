#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class AForm
{
private:
	const std::string mName;
	bool mbIsSigned;
	const int mMinGradeForSign;
	const int mMinGradeForExecute;
	const AForm& operator=(const AForm& rhs);
public:
	AForm(const std::string& name, int minGradeForSign, int minGradeForExecute);
	virtual ~AForm();
	AForm(const AForm& rhs);
	const std::string&	GetName() const;
	bool				GetIsSigned() const;
	int					GetMinGradeForSign() const;
	int					GetMinGradeForExecte() const;
	void				BeSigned(const Bureaucrat& bureaucrat);
	class GradeTooHighException : public std::exception
	{
		virtual const char* what() const _NOEXCEPT
		{
			return "AForm : Grade is too high !";
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

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif 
