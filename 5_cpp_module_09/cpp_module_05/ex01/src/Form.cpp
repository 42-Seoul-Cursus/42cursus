#include "Form.hpp"

Form::Form(const std::string& name, int minGradeForSign, int minGradeForExecute)
: mName(name)
, mbIsSigned(false)
, mMinGradeForSign(minGradeForSign)
, mMinGradeForExecute(minGradeForExecute)
{
	if (mMinGradeForSign < 1 || mMinGradeForExecute < 1)
	{
		throw GradeTooHighException();
	}
	if (mMinGradeForSign > 150 || mMinGradeForExecute > 150)
	{
		throw GradeTooLowException();
	}
}
Form::~Form() {}
Form::Form(const Form& rhs)
: mName(rhs.mName)
, mbIsSigned(rhs.mbIsSigned)
, mMinGradeForSign(rhs.mMinGradeForSign)
, mMinGradeForExecute(rhs.mMinGradeForExecute) {}
const std::string& Form::GetName() const
{
	return mName;
}
bool Form::GetIsSigned() const
{
	return mbIsSigned;
}
int Form::GetMinGradeForSign() const
{
	return mMinGradeForSign;
}
int Form::GetMinGradeForExecte() const
{
	return mMinGradeForExecute;
}
void Form::BeSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.GetGrade() > mMinGradeForSign)
	{
		throw GradeTooLowException();
	}
	mbIsSigned = true;
}
std::ostream& operator<<(std::ostream& os, const Form& form)
{
	os << "Name: " << form.GetName() << '\n'
	<< "Is Signed: " << (form.GetIsSigned() ? "Yes" : "No") << "\n"
    << "Min Grade for Sign: " << form.GetMinGradeForSign() << "\n"
    << "Min Grade for Execute: " << form.GetMinGradeForExecte();
	return os;
}
