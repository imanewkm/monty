#include "monty.h"
/**
 * func_queue - prints the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void func_queue(stack_t **head, unsigned int count)
{
	(void)head;
	(void)count;
	bus.lifi = 1;
}

/**
 * addqueue - add node to the tail stack
 * @n: new_value
 * @head: head of the stack
 * Return: no return
*/
void addqueue(stack_t **head, int n)
{
	stack_t *node, *i;

	i = *head;
	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		printf("Error\n");
	}
	node->n = n;
	node->next_node = NULL;
	if (i)
	{
		while (i->next_node)
			i = i->next_node;
	}
	if (!i)
	{
		*head = node;
		node->prev = NULL;
	}
	else
	{
		i->next = node;
		node->prev = i;
	}
}

/**
 * func_stack - prints the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void func_stack(stack_t **head, unsigned int count)
{
	(void)head;
	(void)count;
	bus.lifi = 0;
}
