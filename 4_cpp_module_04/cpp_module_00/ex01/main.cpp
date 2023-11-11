#include "PhoneBook.h"

int	main()
{
	PhoneBook phonebook;
	std::string input;

	std::cin >> input;
	while (!std::cin.eof() && input != "EXIT")
	{
		if (input == "ADD")
			phonebook.AddContact();
		else if (input == "SEARCH")
			phonebook.SearchContact();
		std::cin >> input;
	}
	return 0;
}
