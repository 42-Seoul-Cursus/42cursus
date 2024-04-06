#include <fstream>
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
: AForm("ShrubberyCreationForm", 145, 137) 
, mTarget(target) {}
ShrubberyCreationForm::~ShrubberyCreationForm() {}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& rhs)
: AForm(rhs) 
, mTarget(rhs.mTarget) {}
void ShrubberyCreationForm::Execute(const Bureaucrat& executor) const
{
	if (!GetIsSigned())
	{
		throw AForm::NoSignatureException();
	}
	if (executor.GetGrade() > GetMinGradeForExecute())
	{
		throw AForm::GradeTooLowException();
	}
	executeForm();
}
void ShrubberyCreationForm::executeForm(void) const
{
	std::ofstream writeFile((mTarget + "_shrubbery").c_str());
	if (!writeFile.is_open())
	{
		throw std::runtime_error("Error opening file");
	}
	std::string asciiTree = 
	"            .        +          .      .          .\n"
	"     .            _        .                    .\n"
	"  ,              /;-._,-.____        ,-----.__\n"
	" ((        .    (_:#::_.:::. `-._   /:, /-._, `._,\n"
	"  `                 \\   _|`\"=:_::.`.);  \\ __/ /\n"
	"                      ,    `./  \\:. `.   )==-'.  .\n"
	"    .      ., ,-=-.  ,\\, +#./`   \\:.  / /           .\n"
	".           \\/:/`-' , ,\\ '` ` `   ): , /_  -o\n"
	"       .    /:+- - + +- : :- + + -:'  /(o-) \\)     .\n"
	"  .      ,=':  \\    ` `/` ' , , ,:' `'--\".--\"---._/`7\n"
	"   `.   (    \\: \\,-._` ` + '\\, ,\"   _,--._,---\":.__/\n"
	"              \\:  `  X` _| _,\\/\\'   .-'\n"
	".               \":._:`\\____  /:'  /      .           .\n"
	"                    \\::.  :\\/:'  /              +\n"
	"   .                 `.:.  /:'  }      .\n"
	"           .           ):_(:;   \\           .\n"
	"                      /:. _/ ,  |\n"
	"                   . (|::.     ,`                  .\n"
	"     .                |::.    \\{\n"
	"                      |:::\\  \\ `.\n"
	"                      |:::(\\    |\n"
	"              O       |:::/{ }  |                  (o\n"
	"               )  ___/#\\::`/ (O \"==._____   O, (O  /`\n"
	"          ~~~w/w~\"~~,\\` `:/,-(~`\"~~~~~~~~\"~o~\\~/~w|/~";
	writeFile.write(asciiTree.c_str(), asciiTree.length());
	writeFile.close();
}
AForm* ShrubberyCreationForm::Clone() const
{
	return new ShrubberyCreationForm(*this);
}
