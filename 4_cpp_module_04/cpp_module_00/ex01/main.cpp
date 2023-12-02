#include "PhoneBook.h"

int	main()
{
	PhoneBook phonebook;
	std::string input;

	while (true)
	{
		std::cout << "Enter the commend (ADD, SEARCH, EXIT)\n";
		std::cin >> input;

		if (input == "ADD")
		{
			phonebook.AddContact();
		}
		else if (input == "SEARCH")
		{
			phonebook.SearchContact();
		}
		if (std::cin.eof() || input == "EXIT")
		{
			break;
		}
	}
	return 0;
}
