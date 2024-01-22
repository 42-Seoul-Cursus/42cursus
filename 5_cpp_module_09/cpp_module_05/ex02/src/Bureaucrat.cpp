#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat()
: mName("Default")
, mGrade(150) {}
Bureaucrat::Bureaucrat(const std::string& name)
: mName(name)
, mGrade(150) {}
Bureaucrat::~Bureaucrat() {};
Bureaucrat::Bureaucrat(const Bureaucrat& rhs)
: mName(rhs.mName)
, mGrade(rhs.mGrade) {}
const std::string& Bureaucrat::GetName() const
{
	return mName;
}
int Bureaucrat::GetGrade() const
{
	return mGrade;
}
void Bureaucrat::Increment(const int amount)
{
	if (amount > 149 || amount < 0)
	{
		throw GradeTooHighException();
	}
	if (mGrade - amount > 150 || mGrade - amount < 1)
	{
		throw GradeTooHighException();
	}
	mGrade -= amount;
}
void Bureaucrat::Decrement(const int amount)
{
	if (amount > 149 || amount < 0)
	{
		throw GradeTooHighException();
	}
	if (mGrade + amount > 150 || mGrade + amount < 1)
	{
		throw GradeTooHighException();
	}
	mGrade += amount;
}
void Bureaucrat::SignForm(Form& form)
{
	try
	{
		form.BeSigned(*this);
		std::cout << mName << " signed " << form.GetName() << std::endl;
	} 
	catch (std::exception& e)
	{
		std::cout << mName << " couldn\'t sign " << form.GetName() << " because " << e.what() << std::endl;
	}
}
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.GetName() << ", bureaucrat grade " << bureaucrat.GetGrade() << '.';
	return os;
}
