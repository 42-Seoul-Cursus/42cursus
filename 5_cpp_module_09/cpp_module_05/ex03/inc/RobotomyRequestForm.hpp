#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
	const std::string mTarget;
	const RobotomyRequestForm& operator=(const RobotomyRequestForm& rhs);
protected:
	virtual void	executeForm(void) const;
public:
	RobotomyRequestForm(const std::string& target);
	virtual ~RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm& rhs);
	virtual void	Execute(const Bureaucrat& executor) const;
	virtual AForm*	Clone() const;
};

#endif 
