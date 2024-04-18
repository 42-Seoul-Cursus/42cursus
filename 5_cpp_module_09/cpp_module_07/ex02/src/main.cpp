#include <iostream>
#include <stdlib.h>
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
	Array<int> arr(10);
	Array<int> emptyArr(0);

	std::cout << arr.size() << std::endl;
	
	for (size_t i = 0; i < 10; i++)
	{
		arr[i] = i + 1;
	}
	for (size_t i = 0; i < 10; i++)
	{
		std::cout << arr[i] << ' ';
	}
	std::cout << std::endl;
	try
	{
		arr[10];
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}
