#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
: mName("Default")
, mGrade(150) {}
Bureaucrat::Bureaucrat(const std::string& name)
: mName(name)
, mGrade(150) {}
Bureaucrat::Bureaucrat(const std::string& name, const int grade)
: mName(name)
, mGrade(grade) {}
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
