#ifndef CONTACT_H
# define CONTACT_H

# include <iostream>
# include <string>
# include <iomanip>

class Contact
{
private:
	std::string mFirstName;
	std::string mLastName;
	std::string mNickname;
	std::string mPhoneNumber;
	std::string mDarkestSecret;
public:
	Contact();
	void				SetFirstName(std::string firstName);
	void				SetLastName(std::string lastName);
	void				SetNickname(std::string nickname);
	void				SetPhoneNumber(std::string phoneNumber);
	void				SetDarkestSecret(std::string darkestSecret);
	std::string	GetFirstName(bool isShort);
	std::string	GetLastName(bool isShort);
	std::string	GetNickname(bool isShort);
	std::string	GetPhoneNumber(bool isShort);
	std::string	GetDarkestSecret(bool isShort);
};

#endif
