#include "Harl.hpp"

int main(void)
{
	Harl harl;
	const char *level[6] = {"DEBUG", "INFO", "WARNING", "ERROR", "das", "HELLO"};

	for (int i = 0; i < 6; i++)
	{
		harl.Complain(level[i]);
	}

}
