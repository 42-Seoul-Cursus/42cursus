#include "AForm.hpp"

AForm::AForm(const std::string& name, int minGradeForSign, int minGradeForExecute)
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
AForm::~AForm() {}
AForm::AForm(const AForm& rhs)
: mName(rhs.mName)
, mbIsSigned(rhs.mbIsSigned)
, mMinGradeForSign(rhs.mMinGradeForSign)
, mMinGradeForExecute(rhs.mMinGradeForExecute) {}
const std::string& AForm::GetName() const
{
	return mName;
}
bool AForm::GetIsSigned() const
{
	return mbIsSigned;
}
int AForm::GetMinGradeForSign() const
{
	return mMinGradeForSign;
}
int AForm::GetMinGradeForExecte() const
{
	return mMinGradeForExecute;
}
void AForm::BeSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.GetGrade() > mMinGradeForSign)
	{
		throw GradeTooLowException();
	}
	mbIsSigned = true;
}
std::ostream& operator<<(std::ostream& os, const AForm& Aform)
{
	os << "\033[3;37m"
	<< "Name: " << Aform.GetName() << '\n'
	<< "Is Signed: " << (Aform.GetIsSigned() ? "Yes" : "No") << '\n'
    << "Min Grade for Sign: " << Aform.GetMinGradeForSign() << '\n'
    << "Min Grade for Execute: " << Aform.GetMinGradeForExecte() << "\033[0m";
	return os;
}
