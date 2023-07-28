#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct s_node
{
	int				data;
	struct s_node	*next;
}					t_node;

typedef struct s_queue
{
	int				size;
	struct s_node	*front;
	struct s_node	*rear;
}					t_queue;

void	init_queue(t_queue *queue)
{
	queue->size = 0;
	queue->front = NULL;
	queue->rear = NULL;
}

t_node	*make_node(int data)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	node->data = data;
	node->next = NULL;
	return (node);
}

int		is_empty(t_queue *queue)
{
	return (queue->size == 0);
}

void	enqueue(t_queue *queue, int data)
{
	t_node	*node;

	node = make_node(data);
	if (is_empty(queue))
		queue->front = node;
	else
		queue->rear->next = node;
	queue->rear = node;
	queue->size++;
}

void	dequeue(t_queue *queue)
{
	t_node	*node;

	if (is_empty(queue))
		return ;
	node = queue->front;
	queue->front = node->next;
	free(node);
	queue->size--;
}

void	print_queue(t_queue *queue)
{
	t_node	*curr;

	curr = queue->front;
	while (curr)
	{
		printf("%d ", curr->data);
		curr = curr->next;
	}
	printf("\n");
}

int	main(void)
{
	t_queue	queue;

	init_queue(&queue);
	enqueue(&queue, 1);
	enqueue(&queue, 2);
	enqueue(&queue, 3);
	enqueue(&queue, 4);
	print_queue(&queue);
	dequeue(&queue);
	print_queue(&queue);
	dequeue(&queue);
	print_queue(&queue);
	dequeue(&queue);
	dequeue(&queue);
	dequeue(&queue);
	print_queue(&queue);
	return (0);
}
