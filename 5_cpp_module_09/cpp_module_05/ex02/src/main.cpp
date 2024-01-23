#include "AForm.hpp"

int main()
{
	Bureaucrat a("seunan");
	a.Increment(140);

	std::cout << a << std::endl;

	Form form("42", 9, 10);

	a.SignForm(form);
	std::cout << form << std::endl;
	return 0;
}
