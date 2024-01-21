#include "Bureaucrat.hpp"

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
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.GetName() << ", bureaucrat grade " << bureaucrat.GetGrade() << '.';
	return os;
}
