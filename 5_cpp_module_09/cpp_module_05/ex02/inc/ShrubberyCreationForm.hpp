#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP_HPP

#include "AForm.hpp"

class SHRUBBERYCREATIONFORM_HPP : public AForm
{
private:
	const std::string mName;
	bool mbIsSigned;
	const int mMinGradeForSign;
	const int mMinGradeForExecute;
	const SHRUBBERYCREATIONFORM_HPP& operator=(const SHRUBBERYCREATIONFORM_HPP& rhs);
public:
	SHRUBBERYCREATIONFORM_HPP(const std::string& name, int minGradeForSign, int minGradeForExecute);
	virtual ~SHRUBBERYCREATIONFORM_HPP();
	SHRUBBERYCREATIONFORM_HPP(const SHRUBBERYCREATIONFORM_HPP& rhs);
	const std::string&	GetName() const;
	bool				GetIsSigned() const;
	int					GetMinGradeForSign() const;
	int					GetMinGradeForExecte() const;
	void				BeSigned(const Bureaucrat& bureaucrat);
	class GradeTooHighException : public std::exception
	{
		virtual const char* what() const _NOEXCEPT
		{
			return "SHRUBBERYCREATIONFORM_HPP : Grade is too high !";
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

std::ostream& operator<<(std::ostream& os, const SHRUBBERYCREATIONFORM_HPP& form);

#endif 
