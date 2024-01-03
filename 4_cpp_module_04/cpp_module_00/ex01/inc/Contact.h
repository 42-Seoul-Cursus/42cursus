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
	void		SetFirstName(std::string firstName);
	void		SetLastName(std::string lastName);
	void		SetNickname(std::string nickname);
	void		SetPhoneNumber(std::string phoneNumber);
	void		SetDarkestSecret(std::string darkestSecret);
	std::string	GetFirstName(void) const;
	std::string	GetLastName(void) const;
	std::string	GetNickname(void) const;
	std::string	GetPhoneNumber(void) const;
	std::string	GetDarkestSecret(void) const;
	std::string	GetShortFirstName(void) const;
	std::string	GetShortLastName(void) const;
	std::string	GetShortNickname(void) const;
	std::string	GetShortPhoneNumber(void) const;
	std::string	GetShortDarkestSecret(void) const;
};

#endif
