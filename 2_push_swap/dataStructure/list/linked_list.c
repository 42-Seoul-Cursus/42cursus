#include <stdio.h>
#include <stdlib.h>

void	leak(void)
{
	system("leaks a.out > leaks_result_temp; cat leaks_result_temp | grep leaked && rm -rf leaks_result_temp");
}

typedef struct	s_list
{
	int				size;
	struct s_node	*head;
	struct s_node	*tail;
}				t_list;

typedef struct	s_node
{
	int				data;
	struct s_node	*next;
}				t_node;

void	init_list(t_list *list)
{
	list->size = 0;
	list->head = NULL;
	list->tail = NULL;
}

t_node	*make_node(int data)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	node->data = data;
	node->next = NULL;
	return (node);
}

void	add_list_last(t_list *list, t_node *node)
{
	if (list->size == 0)
	{
		list->head = node;
		list->tail = node;
	}
	else
	{
		list->tail->next = node;
		list->tail = node;
	}
	list->size++;
}

void	add_list(t_list *list, t_node *node, int idx)
{
	t_node	*curr;
	t_node	*next;

	if (idx == 0)
	{
		node->next = list->head;
		list->head = node;
	}
	else
	{
		curr = list->head;
		while (--idx)
			curr = curr->next;
		next = curr->next;
		curr->next = node;
		node->next = next;
	}
	list->size++;
}

void	delete_list(t_list *list, int idx)
{
	t_node	*curr;
	t_node	*next;

	if (idx == 0)
	{
		next = list->head->next;
		free(list->head);
		list->head = next;
	}
	else
	{
		curr = list->head;
		while (--idx)
			curr = curr->next;
		next = curr->next->next;
		free(curr->next);
		curr->next = next;
	}
	list->size--;
}

void	print_list(t_list *list)
{
	t_node	*curr;

	curr = list->head;
	while (curr)
	{
		printf("%d ", curr->data);
		curr = curr->next;
	}
	printf("\n");
}

void	free_list(t_list *list)
{
	t_node	*curr;
	t_node	*next;

	curr = list->head;
	while (curr)
	{
		next = curr->next;
		curr->data = 0;
		free(curr);
		curr = next;
	}
}

int	main(void)
{
	atexit(leak);
	t_list	list;
	init_list(&list);

	add_list_last(&list, make_node(1));
	add_list_last(&list, make_node(2));
	add_list_last(&list, make_node(3));
	add_list_last(&list, make_node(4));
	add_list_last(&list, make_node(5));
	add_list_last(&list, make_node(6));
	add_list_last(&list, make_node(7));
	add_list(&list, make_node(8), 1);
	delete_list(&list, 0);
	print_list(&list);
	free_list(&list);
	return (0);
}
