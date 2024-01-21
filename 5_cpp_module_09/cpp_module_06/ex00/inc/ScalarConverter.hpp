#ifndef SCALARCONVERTER_CPP
#define SCALARCONVERTER_CPP

#include <string>

class ScalarConverter
{
private:
	ScalarConverter();
	~ScalarConverter();
	ScalarConverter(const ScalarConverter& rhs);
	const ScalarConverter& operator=(const ScalarConverter& rhs);
public:
	static void Convert(std::string& literal);
};

#endif
