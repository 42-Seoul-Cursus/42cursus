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
std::string Contact::GetFirstName(void) const
{
	return mFirstName;
}
std::string Contact::GetLastName(void) const
{
	return mLastName;
}
std::string Contact::GetNickname(void) const
{
	return mNickname;
}
std::string Contact::GetPhoneNumber(void) const
{
	return mPhoneNumber;
}
std::string Contact::GetDarkestSecret(void) const
{
	return mDarkestSecret;
}
std::string Contact::GetShortFirstName(void) const
{
	if (mFirstName.length() > 10)
		return mFirstName.substr(0, 9) + ".";
	return mFirstName;
}
std::string Contact::GetShortLastName(void) const
{
	if (mLastName.length() > 10)
		return mLastName.substr(0, 9) + ".";
	return mLastName;
}
std::string Contact::GetShortNickname(void) const
{
	if (mNickname.length() > 10)
		return mNickname.substr(0, 9) + ".";
	return mNickname;
}
std::string Contact::GetShortPhoneNumber(void) const
{
	if (mPhoneNumber.length() > 10)
		return mPhoneNumber.substr(0, 9) + ".";
	return mPhoneNumber;
}
std::string Contact::GetShortDarkestSecret(void) const
{
	if (mDarkestSecret.length() > 10)
		return mDarkestSecret.substr(0, 9) + ".";
	return mDarkestSecret;
}
