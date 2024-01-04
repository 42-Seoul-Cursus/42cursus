#include "Karen.hpp"

int main(void)
{
	Karen karen;
	const char *level[6] = {"DEBUG", "INFO", "WARNING", "ERROR", "das", "HELLO"};

	for (int i = 0; i < 6; i++)
	{
		karen.Complain(level[i]);
	}

}
