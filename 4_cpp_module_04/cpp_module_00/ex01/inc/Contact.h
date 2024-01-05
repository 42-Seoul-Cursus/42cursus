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
	const std::string&	GetFirstName(void) const;
	const std::string&	GetLastName(void) const;
	const std::string&	GetNickname(void) const;
	const std::string&	GetPhoneNumber(void) const;
	const std::string&	GetDarkestSecret(void) const;
	const std::string&	GetShortFirstName(void) const;
	const std::string&	GetShortLastName(void) const;
	const std::string&	GetShortNickname(void) const;
	const std::string&	GetShortPhoneNumber(void) const;
	const std::string&	GetShortDarkestSecret(void) const;
};

#endif
