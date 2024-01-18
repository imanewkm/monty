#include "monty.h"

/**
* func_pall - function that prints everything in the stack
* @head: double head pointer to the stack
* @count: unused line count
*
* Return: nothing
*/
void func_pall(stack_t **head, unsigned int count)
{
	stack_t *h;
	(void)count;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}

/**
* func_swap - function that swaps the top two elements of the stack
* @head: head of stack
* @count: line count
*
* Return: nothing
*/
void func_swap(stack_t **head, unsigned int count)
{
	stack_t *h;
	int length = 0, temp;

	h = *head;
	while (h)
	{
		h = h->next;
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	temp = h->n;
	h->n = h->next->n;
	h->next->n = temp;
}
