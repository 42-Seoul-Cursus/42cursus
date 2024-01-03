#include "PhoneBook.h"

static std::string GetInput(std::string prompt)
{
	std::string input;

	std::cout << prompt << ": ";
	std::getline(std::cin, input);
	return input;
}
PhoneBook::PhoneBook()
{
	mCnt = 0;
	mCurIdx = 0;
}
void PhoneBook::AddContact()
{
	std::cin.ignore();
	mContacts[mCurIdx].SetFirstName(GetInput("first name"));
	if (std::cin.eof()) return ;
	mContacts[mCurIdx].SetLastName(GetInput("last name"));
	if (std::cin.eof()) return ;
	mContacts[mCurIdx].SetNickname(GetInput("nickname"));
	if (std::cin.eof()) return ;
	mContacts[mCurIdx].SetPhoneNumber(GetInput("phone number"));
	if (std::cin.eof()) return ;
	mContacts[mCurIdx].SetDarkestSecret(GetInput("darkest secret"));
	std::cout << "\033[0;32m" << "Contact added" << "\033[0m" << std::endl;
	++mCurIdx;
	if (mCurIdx >= 8)
		mCurIdx = 0;
	if (mCnt < 8)
		++mCnt;
}
void PhoneBook::SearchContact()
{
	int i;
	std::string input;

	if (mCnt == 0)
	{
		std::cout << "\033[0;33m" << "PhoneBook is empty" << "\033[0m" <<  std::endl;
		return;
	}
	std::cout << "     index|first name| last name|  nickname" << std::endl;
	for (i = 0; i < mCnt; ++i)
	{
		std::cout << std::setw(10) << i << "|";
		std::cout << std::setw(10) << mContacts[i].GetFirstName(true) << "|";
		std::cout << std::setw(10) << mContacts[i].GetLastName(true) << "|";
		std::cout << std::setw(10) << mContacts[i].GetNickname(true) << std::endl;
	}
	std::cout << "Enter index: ";
	std::cin >> input;
	if (!(input.length() == 1 && '0' <= input[0] && input[0] < mCnt + '0'))
	{
		std::cout << "\033[0;31m" << "Invalid index" << "\033[0m" << std::endl;
		return;
	}
	i = input[0] - '0';
	std::cout << "first name: " << mContacts[i].GetFirstName(false) << std::endl;
	std::cout << "last name: " << mContacts[i].GetLastName(false) << std::endl;
	std::cout << "nickname: " << mContacts[i].GetNickname(false) << std::endl;
	std::cout << "phone number: " << mContacts[i].GetPhoneNumber(false) << std::endl;
}
