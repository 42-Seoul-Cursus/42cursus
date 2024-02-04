#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Intern someRandomIntern;
	AForm* form;
	form = someRandomIntern.MakeForm("robotomy request", "Bender");

	Bureaucrat seunan("seunan", 5);
	seunan.SignForm(*form);
	form->Execute(seunan);

	form = someRandomIntern.MakeForm("shrubbery creation", "Home");
	seunan.SignForm(*form);
	form->Execute(seunan);

	form = someRandomIntern.MakeForm("presidential pardon", "seunan");
	seunan.SignForm(*form);
	form->Execute(seunan);
	return 0;
}
