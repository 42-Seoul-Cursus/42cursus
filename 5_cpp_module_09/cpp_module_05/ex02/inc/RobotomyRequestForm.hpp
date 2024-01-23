#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
	const std::string mName;
	bool mbIsSigned;
	const int mMinGradeForSign;
	const int mMinGradeForExecute;
	const RobotomyRequestForm& operator=(const RobotomyRequestForm& rhs);
public:
	RobotomyRequestForm(const std::string& name, int minGradeForSign, int minGradeForExecute);
	virtual ~RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm& rhs);
	const std::string&	GetName() const;
	bool				GetIsSigned() const;
	int					GetMinGradeForSign() const;
	int					GetMinGradeForExecte() const;
	void				BeSigned(const Bureaucrat& bureaucrat);
	class GradeTooHighException : public std::exception
	{
		virtual const char* what() const _NOEXCEPT
		{
			return "RobotomyRequestForm : Grade is too high !";
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

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& form);

#endif 
