#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
: AForm("PresidentialPardonForm", 25, 5) 
, mTarget(target) {}
PresidentialPardonForm::~PresidentialPardonForm() {}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& rhs)
: AForm(rhs) 
, mTarget(rhs.mTarget) {}
void PresidentialPardonForm::Execute(const Bureaucrat& executor) const
{
	if (!GetIsSigned())
	{
		throw AForm::NoSignatureException();
	}
	if (executor.GetGrade() > GetMinGradeForExecute())
	{
		throw AForm::GradeTooLowException();
	}
	executeForm();
}
void PresidentialPardonForm::executeForm(void) const
{
	std::cout << mTarget << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
AForm* PresidentialPardonForm::Clone() const
{
	return new PresidentialPardonForm(*this);
}
