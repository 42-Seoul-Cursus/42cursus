#include <iostream>
#include "Array.tpp"

// export MallocStackLogging=1 when you're finished unset MallocStackLogging.
// To view detailed information about leaks, use the gcc -g option.
// while true; do leaks a.out; sleep 1; done;
void	leak(void)
{
	system("leaks -q array");
}

int	main()
{
	atexit(leak);
	Array<int> arrInt(10);

	std::cout << arrInt.size() << std::endl;
	
	for (size_t i = 0; i < 10; i++)
	{
		arrInt[i] = i + 1;
	}
	for (size_t i = 0; i < 10; i++)
	{
		std::cout << arrInt[i] << ' ';
	}
	std::cout << std::endl;
	try
	{
		arrInt[10];
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}
