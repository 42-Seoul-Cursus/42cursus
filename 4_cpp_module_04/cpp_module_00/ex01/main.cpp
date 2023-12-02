#include "PhoneBook.h"

int	main()
{
	PhoneBook phonebook;
	std::string input;

	std::cout << "Enter the commend (ADD, SEARCH, EXIT)\n";
	std::cin >> input;
	while (!std::cin.eof() && input != "EXIT")
	{
		if (input == "ADD")
			phonebook.AddContact();
		else if (input == "SEARCH")
			phonebook.SearchContact();
		std::cout << "Enter the commend (ADD, SEARCH, EXIT)\n";
		std::cin >> input;
	}
	return 0;
}
