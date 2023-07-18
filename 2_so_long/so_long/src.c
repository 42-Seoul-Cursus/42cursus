#include "so_long.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*mem;

	mem = malloc(size * count);
	if (!mem)
		return (0);
	i = 0;
	while (i < count * size)
		mem[i++] = 0;
	return ((void *) mem);
}
