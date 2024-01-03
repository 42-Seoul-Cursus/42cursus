#include "PhoneBook.h"

int	main()
{
	PhoneBook phonebook;
	std::string input;

	while (true)
	{
		std::cout << "\033[0;37m" << "Enter the commend (ADD, SEARCH, EXIT)\n" << "\033[0m";
		std::cin >> input;

		if (input == "ADD")
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
		if (std::cin.eof() || input == "EXIT")
		{
			break;
		}
	}
	return 0;
}
