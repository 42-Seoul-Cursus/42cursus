#include "Form.hpp"

int main()
{
	Bureaucrat a("seunan", 150);
	a.Increment(140);
	std::cout << a << std::endl;

	Form form("42", 9, 10);

	a.SignForm(form);
	std::cout << form << std::endl;
	return 0;
}
