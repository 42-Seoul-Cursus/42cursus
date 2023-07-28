#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void	show_arr(int *arr, int size, int target)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == target)
			printf("\x1b[34m%d\x1b[0m ", target);
		else
			printf("%d ", arr[i]);
	}
	printf("\n");
}

void	bubble_sort(int *arr, int size)
{
	int	tmp;

	for (int i = 0; i < size; i++)
	{
		tmp = arr[i];
		for (int j = i; j < size; j++)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}

}

int	is_even(int n)
{
	return (n % 2 == 0);
}

int	binary_search(int *arr, int size, int target)
{
	int	left;
	int	right;
	int	mid;

	left = 0;
	right = size - 1;
	printf("target: %d\n", target);
	while (left <= right)
	{
		mid = (left + right) / 2;
		show_arr(arr, size, arr[mid]);
		if (arr[mid] == target)
			return (mid);
		else if (arr[mid] < target)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return (-1);
}

int	main(void)
{
	int	arr[10];
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
		arr[i] = rand() % 100;
	bubble_sort(arr, 10);
	binary_search(arr, 10, arr[rand() % 10]);
	return (0);
}
