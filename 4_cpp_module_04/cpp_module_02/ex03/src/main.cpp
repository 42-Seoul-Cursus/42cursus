#include "Point.hpp"

int	main()
{
	if (bsp(Point(0, 0), Point(1, 0), Point(0, 1), Point(0.1, 0.5)))
	{
		std::cout << "The point is inside a triangle !" << std::endl;
	}
	else
	{
		std::cout << "The point is not inside a triangle..." << std::endl;
	}
	return 0;
}
