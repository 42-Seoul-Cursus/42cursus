#include "PhoneBook.h"

int	main()
{
	PhoneBook phonebook;
	std::string input;

	while (!std::cin.eof())
	{
		std::cout << "\033[0;37m" << "Enter the commend (ADD, SEARCH, EXIT)\n" << "\033[0m";
		std::cin >> input;
		std::cin.ignore();

		if (std::cin.eof() || input == "EXIT")
		{
			break;
		}
		else if (input == "ADD")
		{
			phonebook.AddContact();
		}
		else if (input == "SEARCH")
		{
			phonebook.SearchContact();
		}
		else
		{
			std::cout << "\033[0;31m\"" << input << "\" is not commend\n" << "\033[0m";
		}
	}
	return 0;
}
