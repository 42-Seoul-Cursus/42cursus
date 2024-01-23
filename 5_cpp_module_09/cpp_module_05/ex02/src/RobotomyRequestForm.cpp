#include <random>
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
: AForm("RobotomyRequestForm", 72, 45) 
, mTarget(target) {}
RobotomyRequestForm::~RobotomyRequestForm() {}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& rhs)
: AForm(rhs) 
, mTarget(rhs.mTarget) {}
void RobotomyRequestForm::Execute(const Bureaucrat& executor) const
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
void RobotomyRequestForm::executeForm(void) const
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(0, 1);

	std::cout << "mWhirr, whirr, whirr... ";
	switch (dis(gen))
	{
	case 0:
		std::cout << "\033[0;32m" 
		<< mTarget << " has been robotomized successfully !" 
		<< "\033[0m" << std::endl;
		break;
	default:
		std::cout << "\033[0;31m"
		<< mTarget << " robotomy failed..."
		<< "\033[0m" << std::endl;
		break;
	}
}
