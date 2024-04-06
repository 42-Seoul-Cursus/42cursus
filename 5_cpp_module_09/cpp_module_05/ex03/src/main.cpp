#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void	leak(void)
{
	system("leaks --list intern | grep 'total leaked bytes'");
}

int main()
{
	atexit(leak);
	Intern someRandomIntern;
	AForm* form;

	Bureaucrat seunan("seunan", 5);
	const std::string names[4] = {"shrubbery creation", "robotomy request", "presidential pardon", "random"};

	for (size_t i = 0; i < 4; i++)
	{
		form = someRandomIntern.MakeForm(names[i], "target");
		if (form == NULL)
		{
			continue;
		}
		seunan.SignForm(*form);
		form->Execute(seunan);
		delete form;
	}
	return 0;
}
