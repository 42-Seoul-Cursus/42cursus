#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.h"

class PhoneBook
{
private:
	Contact mContacts[8];
	int mCurIdx;
	int mCnt;
public:
	PhoneBook();
	void	AddContact();
	void	SearchContact();
};

#endif
