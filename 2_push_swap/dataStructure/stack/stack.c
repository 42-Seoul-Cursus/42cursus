#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct	s_stack
{
	int				size;
	struct s_node	*top;
}				t_stack;

typedef struct	s_node
{
	int				data;
	struct s_node	*next;
}				t_node;

void	search_data(t_stack *stack, int data)
{
	t_node	*curr;

	curr = stack->top;
	while (curr)
	{
		if (curr->data == data)
		{
			printf("found: %d\n", data);
			return ;
		}
		curr = curr->next;
	}
	printf("not found: %d\n", data);
}

void	init_stack(t_stack *stack)
{
	stack->size = 0;
	stack->top = NULL;
}

t_node	*make_node(int data)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	node->data = data;
	node->next = NULL;
	return (node);
}

void	push(t_stack *stack, int data)
{
	t_node	*node;

	node = make_node(data);
	node->next = stack->top;
	stack->top = node;
	stack->size++;
}

void	pop(t_stack *stack)
{
	t_node	*tmp;

	if (stack->size == 0)
	{
		printf("stack is empty\n");
		return ;
	}
	printf("pop: %d\n", stack->top->data);
	tmp = stack->top;
	stack->top = stack->top->next;
	free(tmp);
	stack->size--;
}

void	print_stack(t_stack *stack)
{
	t_node	*curr;

	curr = stack->top;
	while (curr)
	{
		printf("%d ", curr->data);
		curr = curr->next;
	}
	printf("\n");
}

int	main(void)
{
	t_stack	stack;

	push(&stack, 1);
	push(&stack, 2);
	push(&stack, 3);
	pop(&stack);
	return (0);
}
