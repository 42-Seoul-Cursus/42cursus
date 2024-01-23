#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat a("seunan");
	a.Increment(145);

	std::cout << a << std::endl;

	ShrubberyCreationForm home("home");
	std::cout << home << std::endl;
	a.ExecuteForm(home);
	a.SignForm(home);
	a.ExecuteForm(home);
	
	PresidentialPardonForm b("b");
	std::cout << b << std::endl;
	a.ExecuteForm(b);
	a.SignForm(b);
	a.ExecuteForm(b);

	RobotomyRequestForm c("c");
	std::cout << c << std::endl;
	a.ExecuteForm(c);
	a.SignForm(c);
	a.ExecuteForm(c);
	return 0;
}
