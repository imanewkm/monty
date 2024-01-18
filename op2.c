#include "monty.h"
/**
 * func_mod - computes
 * @head: head of stack
 * @count: line num
 * Return: Always 0 (Success)
 */
void func_mod(stack_t **head, unsigned int count)
{
	stack_t *n;
	int length = 0, i;

	n = *head;
	while (n)
	{
		n = n->node;
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	i = n->node % n->j;
	n->next->j = i;
	*head = n->node;
	free(n);
}

/**
 * func_mul - multiples the top 2 elements of a stack
 * @head: stack head
 * @count: 
