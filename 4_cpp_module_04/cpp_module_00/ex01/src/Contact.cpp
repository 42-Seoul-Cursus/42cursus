#include "Contact.h"

Contact::Contact()
{
	mFirstName = "";
	mLastName = "";
	mNickname = "";
	mPhoneNumber = "";
	mDarkestSecret = "";
}
void Contact::SetFirstName(std::string firstName)
{
	mFirstName = firstName;
}
void Contact::SetLastName(std::string lastName)
{
	mLastName = lastName;
}
void Contact::SetNickname(std::string nickname)
{
	mNickname = nickname;
}
void Contact::SetPhoneNumber(std::string phoneNumber)
{
	mPhoneNumber = phoneNumber;
}
void Contact::SetDarkestSecret(std::string darkestSecret)
{
	mDarkestSecret = darkestSecret;
}
const std::string&	Contact::GetFirstName(void) const
{
	return mFirstName;
}
const std::string&	Contact::GetLastName(void) const
{
	return mLastName;
}
const std::string&	Contact::GetNickname(void) const
{
	return mNickname;
}
const std::string&	Contact::GetPhoneNumber(void) const
{
	return mPhoneNumber;
}
const std::string&	Contact::GetDarkestSecret(void) const
{
	return mDarkestSecret;
}
const std::string&	Contact::GetShortFirstName(void) const
{
	if (mFirstName.length() > 10)
		return mFirstName.substr(0, 9) + ".";
	return mFirstName;
}
const std::string&	Contact::GetShortLastName(void) const
{
	if (mLastName.length() > 10)
		return mLastName.substr(0, 9) + ".";
	return mLastName;
}
const std::string&	Contact::GetShortNickname(void) const
{
	if (mNickname.length() > 10)
		return mNickname.substr(0, 9) + ".";
	return mNickname;
}
const std::string&	Contact::GetShortPhoneNumber(void) const
{
	if (mPhoneNumber.length() > 10)
		return mPhoneNumber.substr(0, 9) + ".";
	return mPhoneNumber;
}
const std::string&	Contact::GetShortDarkestSecret(void) const
{
	if (mDarkestSecret.length() > 10)
		return mDarkestSecret.substr(0, 9) + ".";
	return mDarkestSecret;
}
