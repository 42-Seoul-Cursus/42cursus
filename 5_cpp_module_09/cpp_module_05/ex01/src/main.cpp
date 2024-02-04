#include "Form.hpp"

int main()
{
	try
	{
		Bureaucrat a("seunan", 151);
		a.Increment(140);
		std::cout << a << std::endl;

		Form form("42", 151, 10);

		a.SignForm(form);
		std::cout << form << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}
