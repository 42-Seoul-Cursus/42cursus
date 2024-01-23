#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat five("five", 5);
	Bureaucrat fifty("fifty", 50);
	Bureaucrat oneHundredFifty("oneHundredFifty", 150);

	std::cout << five << '\n' << fifty << '\n' << oneHundredFifty << std::endl;

	std::cout << "\n\033[1;32m"
	<< "ShrubberyCreationForm Test"
	<< "\033[0m" << std::endl;

	ShrubberyCreationForm home("home");
	std::cout << home << std::endl;
	five.ExecuteForm(home);
	fifty.ExecuteForm(home);
	oneHundredFifty.ExecuteForm(home);
	five.SignForm(home);
	fifty.SignForm(home);
	oneHundredFifty.SignForm(home);
	five.ExecuteForm(home);
	fifty.ExecuteForm(home);
	oneHundredFifty.ExecuteForm(home);
	
	std::cout << "\n\033[1;32m"
	<< "PresidentialPardonForm Test"
	<< "\033[0m" << std::endl;

	PresidentialPardonForm b("b");
	std::cout << b << std::endl;
	five.ExecuteForm(b);
	fifty.ExecuteForm(b);
	oneHundredFifty.ExecuteForm(b);
	five.SignForm(b);
	fifty.SignForm(b);
	oneHundredFifty.SignForm(b);
	five.ExecuteForm(b);
	fifty.ExecuteForm(b);
	oneHundredFifty.ExecuteForm(b);

	std::cout << "\n\033[1;32m"
	<< "PresidentialPardonForm Test"
	<< "\033[0m" << std::endl;

	RobotomyRequestForm c("c");
	std::cout << c << std::endl;
	five.ExecuteForm(c);
	fifty.ExecuteForm(c);
	oneHundredFifty.ExecuteForm(c);
	five.SignForm(c);
	fifty.SignForm(c);
	oneHundredFifty.SignForm(c);
	five.ExecuteForm(c);
	fifty.ExecuteForm(c);
	oneHundredFifty.ExecuteForm(c);
	return 0;
}
