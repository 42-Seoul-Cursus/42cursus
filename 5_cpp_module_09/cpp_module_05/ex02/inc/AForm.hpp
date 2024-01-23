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
protected:
	virtual void		executeForm(void) const = 0;
public:
	AForm(const std::string& name, int minGradeForSign, int minGradeForExecute);
	virtual ~AForm();
	AForm(const AForm& rhs);
	const std::string&	GetName() const;
	bool				GetIsSigned() const;
	int					GetMinGradeForSign() const;
	int					GetMinGradeForExecute() const;
	void				BeSigned(const Bureaucrat& bureaucrat);
	virtual void		Execute(const Bureaucrat& executor) const = 0;
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
	class NoSignatureException : public std::exception
	{
		virtual const char* what() const _NOEXCEPT
		{
			return "\033[0;31mForm is not signed !\033[0m";
		}
	};
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif 
