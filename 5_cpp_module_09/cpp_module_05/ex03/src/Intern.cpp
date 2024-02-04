#include <iostream>
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}
Intern::~Intern() {}
AForm* Intern::MakeForm(const std::string& name, const std::string& target)
{
	ShrubberyCreationForm a(target);
	RobotomyRequestForm b(target);
	PresidentialPardonForm c(target);

	const AForm* forms[3] = { &a, &b, &c };
	const std::string names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	for (size_t i = 0; i < 3; i++)
	{
		if (names[i] == name)
		{
			std::cout << "\033[0;32m" 
			<< "Intern creates " << names[i]
			<< "\033[0m" << std::endl;
			return forms[i]->Clone();
		}
	}
	std::cout << "\033[0;31m" 
	<< "Intern failed to create the form."
	<< "\033[0m" << std::endl;
	return NULL;
}
