#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	const std::string mTarget;
	const PresidentialPardonForm& operator=(const PresidentialPardonForm& rhs);
protected:
	virtual void	executeForm(void) const;
public:
	PresidentialPardonForm(const std::string& target);
	virtual ~PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm& rhs);
	virtual void	Execute(const Bureaucrat& executor) const;
	virtual AForm*	Clone() const;
};

#endif 
