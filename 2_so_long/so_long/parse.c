#include "so_long.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}

t_list	*ft_lstnew_idx(void *content, int idx)
{
	t_list	*new;

	new = ft_calloc(1, sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	new->index = idx;
	return (new);
}

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
		ft_lstadd_back(map, ft_lstnew_idx(buf, i));
		++i;
	}
	// while (*map != NULL)
	// {
	// 	printf("%d %s",(*map)->index, (*map)->content);
	// 	(*map) = (*map)->next;
	// }

}
