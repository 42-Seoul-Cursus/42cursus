#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat()
: mName("Default")
, mGrade(150) {}
Bureaucrat::Bureaucrat(const std::string& name)
: mName(name)
, mGrade(150) {}
Bureaucrat::Bureaucrat(const std::string& name, const int grade)
: mName(name)
, mGrade(grade)
{
	if (mGrade > 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
	if (mGrade < 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
}
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
	int increasedGrade = mGrade - amount;

	if (amount > 149 || amount < 0 
	||increasedGrade > 150 ||increasedGrade < 1)
	{
		throw GradeTooHighException();
	}
	mGrade = increasedGrade;
}
void Bureaucrat::Decrement(const int amount)
{
	int decreasedGrade = mGrade + amount;

	if (amount > 149 || amount < 0 
	||decreasedGrade > 150 ||decreasedGrade < 1)
	{
		throw GradeTooLowException();
	}
	mGrade = decreasedGrade;
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
