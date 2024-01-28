#include <sstream>
#include "ScalarConverter.hpp"
#include "ScalarConverterStuff.hpp"

void ScalarConverter::Convert(std::string& literal)
{
	if (ScalarConverterStuff::IsFloat(literal))
	{
		literal.pop_back();
	}
	if (!ScalarConverterStuff::IsValidLiteral(literal))
	{
		ScalarConverterStuff::PrintNan();
		return ;
	}

	std::istringstream iss(literal);

	double num;
	iss >> num;

	ScalarConverterStuff::PrintChar(num);
	ScalarConverterStuff::PrintInt(num);
	ScalarConverterStuff::PrintFloat(num);
	ScalarConverterStuff::PrintDouble(num);
}
