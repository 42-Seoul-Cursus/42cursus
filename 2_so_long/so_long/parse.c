#include "so_long.h"

void	parse_map(t_list **map, t_vars *vars)
{
	int		i;
	char	*buf;

	i = 0;
	while (1)
	{
		buf = get_next_line(vars->fd);
		if (buf == NULL)
			break;
		ft_lstadd_back(map, ft_lstnew(buf, i++));
	}
	vars->x = ft_strlen((*map)->content);
	vars->y = i;
	// while (*map != NULL)
	// {
	// 	printf("%d %s\n",(*map)->index, (*map)->content);
	// 	(*map) = (*map)->next;
	// }
}
