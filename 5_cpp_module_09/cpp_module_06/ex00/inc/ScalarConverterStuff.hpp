#ifndef SCALARCONVERTERSTUFF_CPP
#define SCALARCONVERTERSTUFF_CPP

#include <string>

namespace ScalarConverterStuff
{
	bool IsValidLiteral(const std::string& literal);
	bool IsFloat(const std::string& literal);
	void PrintChar(double num);
	void PrintInt(double num);
	void PrintFloat(double num);
	void PrintDouble(double num);
	void PrintNan(void);
}

#endif
