#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
	const std::string mTarget;
	const ShrubberyCreationForm& operator=(const ShrubberyCreationForm& rhs);
protected:
	virtual void	executeForm(void) const;
public:
	ShrubberyCreationForm(const std::string& target);
	virtual ~ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm& rhs);
	virtual void	Execute(const Bureaucrat& executor) const;
	virtual AForm*	Clone() const;
};

#endif 
