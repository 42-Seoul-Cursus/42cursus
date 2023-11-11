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
std::string Contact::GetFirstName(bool isShort)
{
	if (isShort && mFirstName.length() > 10)
		return mFirstName.substr(0, 9) + ".";
	return mFirstName;
}
std::string Contact::GetLastName(bool isShort)
{
	if (isShort && mLastName.length() > 10)
		return mLastName.substr(0, 9) + ".";
	return mLastName;
}
std::string Contact::GetNickname(bool isShort)
{
	if (isShort && mNickname.length() > 10)
		return mNickname.substr(0, 9) + ".";
	return mNickname;
}
std::string Contact::GetPhoneNumber(bool isShort)
{
	if (isShort && mPhoneNumber.length() > 10)
		return mPhoneNumber.substr(0, 9) + ".";
	return mPhoneNumber;
}
std::string Contact::GetDarkestSecret(bool isShort)
{
	if (isShort && mDarkestSecret.length() > 10)
		return mDarkestSecret.substr(0, 9) + ".";
	return mDarkestSecret;
}
